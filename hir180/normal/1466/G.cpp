//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

int n, q;
string s, t;
vector<int>ok_pre[100005], ok_suf[100005];
int cnt[26][100005], lw[100005];
ll bin[100005], rev[100005], R[26][100005], contain[100005];

string cur;
int len[100005], pos = -1;

int lev[100005], beg[100005];
string Q[100005];
vector<P>vec;
ll p[2], hs[2][2000005], rui[2][2][2000005];
ll zan[2][2][1000005];




int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q >> s >> t;
	mt19937 mt(n+q);
	rep(i, q){
		cin >> lev[i] >> Q[i];
		vec.pb(mp(Q[i].size(), i));
	}
	
	SORT(vec);
	
	int nx = 0;
	cur = s;
	len[0] = s.size();
	rep(i, 2) p[i] = 100 + mt()%1000;
	rep(i, 2){
		hs[i][0] = 1;
		for(int ii=1;ii<=len[0]+2;ii++){
			hs[i][ii] = hs[i][ii-1] * p[i] % mod;
		}
		rui[0][i][0] = 0;
		rep(j, cur.size()){
			rui[0][i][j+1] = rui[0][i][j] + 1LL*(cur[j]-'a'+1)*hs[i][j]%mod;
			if(rui[0][i][j+1] >= mod) rui[0][i][j+1] -= mod;
		}
		rui[1][i][0] = 0;
		for(int j=cur.size()-1;j>=0;j--){
			rui[1][i][cur.size()-j] = rui[1][i][cur.size()-j-1]*p[i]%mod;
			rui[1][i][cur.size()-j] += 1LL*(cur[j]-'a'+1);
			if(rui[1][i][cur.size()-j] >= mod) rui[1][i][cur.size()-j] -= mod;
		}
	}
	while(nx < vec.size() && vec[nx].fi <= len[0]){
		int id = vec[nx].sc;
		string S = Q[id];
		
		lw[id] = 0;
		ok_pre[id].resize(S.size()+1, 0); ok_pre[id][0] = 1;
		ok_suf[id].resize(S.size()+1, 0); ok_suf[id][0] = 1;
		rep(i, 2){
			zan[0][i][0] = 0;
			rep(j, S.size()){
				zan[0][i][j+1] = zan[0][i][j] + 1LL*(S[j]-'a'+1)*hs[i][j]%mod;
				if(zan[0][i][j+1] >= mod) zan[0][i][j+1] -= mod;
			}
			zan[1][i][0] = 0;
			for(int j=S.size()-1;j>=0;j--){
				zan[1][i][S.size()-j] = zan[1][i][S.size()-j-1]*p[i]%mod;
				zan[1][i][S.size()-j] += 1LL*(S[j]-'a'+1);
				if(zan[1][i][S.size()-j] >= mod) zan[1][i][S.size()-j] -= mod;
			}
		}
		repn(x, S.size()){
			if(zan[0][0][x] == rui[1][0][x] && zan[0][1][x] == rui[1][1][x]) ok_pre[id][x] = 1;
			if(zan[1][0][x] == rui[0][0][x] && zan[1][1][x] == rui[0][1][x]) ok_suf[id][x] = 1;
		}
		//cout << id << endl;
		//dmp(ok_pre[id]);
		//dmp(ok_suf[id]);
		rep(x, S.size()){
			int a = x;
			int b = S.size()-1-x;
			if(ok_pre[id][a] && ok_suf[id][b]){
				cnt[S[a]-'a'][id] ++;
			}
		}
		for(int i=0;i<cur.size();i++){
			if(i+S.size()-1 >= cur.size()) break;
			rep(q, 2){
				ll k = rui[0][q][i+S.size()];
				k -= rui[0][q][i];
				if(k < 0) k += mod;
				if( (zan[0][q][S.size()] * hs[q][i])%mod == k );
				else goto fail;
			}
			contain[id]++;
			fail:;
		}
		nx++;
		//cout << contain[id] << endl;
	}
	
	rep(i, n){
		len[i+1] = len[i] * 2 + 1;
		chmin(len[i+1], INF/2);
		
		if(nx < vec.size()){
			cur.pb(t[i]);
			cur = cur + cur;
			cur.pop_back();
			rep(i, 2) p[i] = 100 + mt()%1000;
			
			
			rep(i, 2){
				hs[i][0] = 1;
				for(int ii=1;ii<=cur.size()+2;ii++){
					hs[i][ii] = hs[i][ii-1] * p[i] % mod;
				}
				rui[0][i][0] = 0;
				rep(j, cur.size()){
					rui[0][i][j+1] = rui[0][i][j] + 1LL*(cur[j]-'a'+1)*hs[i][j]%mod;
					if(rui[0][i][j+1] >= mod) rui[0][i][j+1] -= mod;
				}
				rui[1][i][0] = 0;
				for(int j=cur.size()-1;j>=0;j--){
					rui[1][i][cur.size()-j] = rui[1][i][cur.size()-j-1]*p[i]%mod;
					rui[1][i][cur.size()-j] += 1LL*(cur[j]-'a'+1);
					if(rui[1][i][cur.size()-j] >= mod) rui[1][i][cur.size()-j] -= mod;
				}
			}
			while(nx < vec.size() && vec[nx].fi <= len[i+1]){
				assert(vec[nx].fi > len[i]);
				int id = vec[nx].sc;
				string S = Q[id];
				
				lw[id] = i+1;
				ok_pre[id].resize(S.size()+1, 0); ok_pre[id][0] = 1;
				ok_suf[id].resize(S.size()+1, 0); ok_suf[id][0] = 1;
				rep(i, 2){
					zan[0][i][0] = 0;
					rep(j, S.size()){
						zan[0][i][j+1] = zan[0][i][j] + 1LL*(S[j]-'a'+1)*hs[i][j]%mod;
						if(zan[0][i][j+1] >= mod) zan[0][i][j+1] -= mod;
					}
					zan[1][i][0] = 0;
					for(int j=S.size()-1;j>=0;j--){
						zan[1][i][S.size()-j] = zan[1][i][S.size()-j-1]*p[i]%mod;
						zan[1][i][S.size()-j] += 1LL*(S[j]-'a'+1);
						if(zan[1][i][S.size()-j] >= mod) zan[1][i][S.size()-j] -= mod;
					}
				}
				repn(x, S.size()){
					if(zan[0][0][x] == rui[1][0][x] && zan[0][1][x] == rui[1][1][x]) ok_pre[id][x] = 1;
					if(zan[1][0][x] == rui[0][0][x] && zan[1][1][x] == rui[0][1][x]) ok_suf[id][x] = 1;
				}
				//cout << id << endl;
				//dmp(ok_pre[id]);
				//dmp(ok_suf[id]);
				rep(x, S.size()){
					int a = x;
					int b = S.size()-1-x;
					if(ok_pre[id][a] && ok_suf[id][b]){
						cnt[S[a]-'a'][id] ++;
						if(S[a] == t[i] && max(a, b) <= len[i]){
							contain[id] ++;
						}
					}
				}
				nx++;
			}
			if(pos == -1 && nx == vec.size()){
				pos = 0;
			}
		}
	}
	while(nx < vec.size()){
		lw[vec[nx].sc] = n + 1;
		nx++;
	}
	bin[0] = 1;
	rev[0] = 1;
	ll a = 2, b = (mod+1)/2;
	repn(i, 100003){
		bin[i] = bin[i-1] * a % mod;
		rev[i] = rev[i-1] * b % mod;
	}
	rep(i, n){
		rep(j, 26) R[j][i+1] = R[j][i];
		R[t[i]-'a'][i+1] += bin[n-1-i];
		R[t[i]-'a'][i+1] %= mod;
	}
	rep(i, q){
		if(lev[i] < lw[i]){
			//smaller
			cout << "0" << '\n';
			continue;
		}
		else{
			int a = lw[i];
			int b = lev[i];
			//cout << contain[i] << " " << b-a << endl;
			ll ans = 1LL * contain[i] * bin[b-a] % mod;
			//cout << ans << endl;
			rep(j, 26){
				ll sum = R[j][b];
				{
					sum -= R[j][a];
					if(sum < 0) sum += mod;
				}
				sum = sum * rev[n-b] % mod * cnt[j][i] % mod;
				ans += sum;
			}
			ans %= mod;
			cout << ans << '\n';
		}
	}
}