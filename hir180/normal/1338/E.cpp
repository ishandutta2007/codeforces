#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
const int INF = 1000000000;
#define mp make_pair
int n, outdeg[8005];
bool ex[8005][8005], rem[8005], reach[8005], isin[8005];
string str[8005];
int conv(char ch){
	if('0' <= ch && ch <= '9') return ch - '0';
	else return 10 + (ch-'A');
}
int tmp[8005], ran[8005];
void alignment(vc<int>&a){
	for(auto x:a){
		for(auto y:a){
			if(x != y) tmp[x] += ex[x][y];
		}
	}
	sort(a.begin(), a.end(), [](const int &a, const int &b){
		return tmp[a] < tmp[b];
	});
}
vector<int>Q[8005];
struct seg{
	#define sz (1<<13)
	int s[sz*2];
	void init(){
		memset(s, 0, sizeof(s));
	}
	void update(int i, int x){
		i += sz-1;
		s[i] = x;
		while(i){
			i = (i-1)/2;
			s[i] = s[i*2+1] + s[i*2+2];
		}
	}
	int get(int a, int b, int k, int l, int r){
		if(r < a || b < l) return 0;
		if(a <= l && r <= b) return s[k];
		return get(a, b, k*2+1, l, (l+r)/2)+
		get(a, b, k*2+2, (l+r)/2+1, r);
	}
	int get(int a, int b){
		return get(a, b, 0, 0, sz-1);
	}
}kaede;
struct seg2{
	#define sz (1<<13)
	int s[sz*2];
	void init(){
		fill(s, s+sz*2, INF);
	}
	void update(int i, int x){
		i += sz-1;
		s[i] = x;
		while(i){
			i = (i-1)/2;
			s[i] = min(s[i*2+1], s[i*2+2]);
		}
	}
	int get(int a, int b, int k, int l, int r){
		if(r < a || b < l) return INF;
		if(a <= l && r <= b) return s[k];
		return min(get(a, b, k*2+1, l, (l+r)/2),
		get(a, b, k*2+2, (l+r)/2+1, r));
	}
	int get(int a, int b){
		return get(a, b, 0, 0, sz-1);
	}
}fuyuko;

void solve(){
	cin >> n;
	rep(i, n) cin >> str[i];
	rep(i, n){
		rep(j, n/4){
			int v = conv(str[i][j]);
			outdeg[i] += __builtin_popcount(v);
			rep(k, 4) ex[i][(j<<2) ^ k] = ((v>>(3-k))&1);
		}
	}
	int zan = n;
	ll ans = 0;
	while(zan){
	    int v = -1;
		rep(i, n){
			if(rem[i]) continue;
			if(outdeg[i] == zan-1) v = i;
		}
		if(v == -1) break;
		//1 vs zan
		ans += zan-1;
		ans += 614LL * n * (zan-1);
		rem[v] = 1;
		rep(i, n) outdeg[i] -= ex[i][v];
		zan--;
	}
	if(zan == 0){
		cout << ans << endl;
		return;
	}
	int g;
	rep(i, n) if(!rem[i]){ g = i; break; }
	vc<int>in, out;
	rep(i, n) if(!rem[i] && g != i){
		if(ex[i][g]){
			in.pb(i);
			isin[i] = 1;
		}
		else out.pb(i);
	}
	//connected...1
	//not connected...2
	ans += 3LL*(zan-1)*zan/2;
	//actually, pairs of distance=3 exist
	alignment(in);
	alignment(out);
	rep(i, in.size()) rep(j, i) assert(ex[in[i]][in[j]]);
	rep(i, out.size()) rep(j, i) assert(ex[out[i]][out[j]]);
	rep(i, in.size()) ran[in[i]] = 1;
	for(auto at:out){
		int v = -1;
		rep(i, in.size()) if(ex[at][in[i]]) v = i;
		rep(i, in.size()) if(i > v && !reach[i]) ans++;
		rep(i, in.size()) if(ex[at][in[i]]) reach[i] = 1;
	}
	//g -> in
	for(auto at:in){
		for(auto at2:out) if(!ex[at][at2]) goto fail;
		ans ++; fail:;
	}
	//out -> g
	for(auto at:out){
		for(auto at2:in) if(ex[at][at2]) goto fail2;
		ans ++; fail2:;
	}
	kaede.init();
	fuyuko.init();
	//in -> in
	rep(j, in.size()){
		int at = in[j];
		int mn = INF, mx = -INF, cnt = 0;
		rep(i, out.size()){
			if(ex[at][out[i]]){
				cnt ++;
				chmin(mn, i);
				chmax(mx, i);
			}
		}
		if(cnt == 0){
			ans += in.size() - 1 - j;
			fuyuko.update(j, out.size());
		}
		else{
			assert(mx-mn+1 == cnt && mx == out.size()-1);
			Q[mn].pb(j);
			fuyuko.update(j, mn);
		}
	}
	rep(i, in.size()) kaede.update(i, 1);
	vector<int>vis(in.size(), 0);
	for(int i=out.size()-1;i>=0;i--){
		rep(j, in.size()){
			if(vis[j] || !ex[out[i]][in[j]]) continue;
			vis[j] = 1;
			kaede.update(j, 0);
		}
		for(auto at:Q[i]){
			ans += kaede.get(at+1, in.size()-1);
		}
	}
	//out -> out
	rep(j, out.size()){
		int at = out[j];
		int mn = INF, mx = -INF, cnt = 0;
		rep(i, in.size()){
			if(ex[at][in[i]]){
				cnt ++;
				chmin(mn, i);
				chmax(mx, i);
			}
		}
		if(cnt == 0){
			ans += out.size() - 1 - j;
		}
		else{
			assert(mx-mn+1 == cnt);
			int p = fuyuko.get(mn, mx);
			if(j < p) ans += p - j - 1;
		}
	}
	cout << ans << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	solve();
}