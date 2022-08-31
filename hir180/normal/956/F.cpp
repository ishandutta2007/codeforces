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
#define per(i,x) for(int i=x-1;i>=0;i--)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
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

typedef bitset<150> bs;
unordered_map<bs, int>M;
int cnt = 0;
bs info[20005];
void add(bs &b){
	if(M.find(b) == M.end()){
		info[cnt] = b;
		M[b] = cnt++;
	}
}
ll go[16005][10];
ll gg[725][10];
ll way[725][20][10];
bool ok[725][10];
int hs[16005],tmp[16005];
int rev[725];

void prepare(){
	bs x = bs();
	x[75] = 1;
	add(x);
	rep(i,cnt){
		rep(nxt,10){
			bs nw = (info[i]<<nxt) | (info[i]>>nxt);
			add(nw);
		}
	}
	rep(i,cnt){
		rep(nxt,10){
			bs nw = (info[i]<<nxt) | (info[i]>>nxt);
			assert(M.find(nw) != M.end());
			go[i][nxt] = M[nw];
		}
	}
	rep(i,cnt){
		int mn = INF;
		rep(j,150){
			if(info[i][j]){
				mn = min(mn, abs(75-j));
			}
		}
		hs[i] = mn;
	}
	int sz = 0;
	while(1){
		map<vector<int>,int>S;
		int nxt = 0;
		rep(i,cnt){
			vector<int>adj;
			rep(j,10){
				adj.pb(hs[go[i][j]]);
			}
			if(S.find(adj) == S.end()){
				S[adj] = nxt++;
			}
		}
		rep(i,cnt){
			vector<int>adj;
			rep(j,10){
				adj.pb(hs[go[i][j]]);
			}
			tmp[i] = S[adj];
		}
		rep(i,cnt) hs[i] = tmp[i];
		if(sz == nxt) break;
		sz = nxt;
	}
	//calc gg, way, ok
	rep(i,cnt){
		rev[hs[i]] = i;
	}
	rep(i,sz){
		int a = rev[i];
		int mn = INF;
		rep(j,150){
			if(info[a][j]){
				mn = min(mn, abs(75-j));
			}
		}
		for(int j=mn;j<10;j++) ok[i][j] = 1;
		for(int j=mn;j<10;j++) way[i][0][j] += 1;
		rep(j,10){
			gg[i][j] = hs[go[a][j]];
		}
	}
	rep(j,19){
		rep(k,10){
			rep(i,sz){
				rep(nxt,10){
					int g = gg[i][nxt];
					way[i][j+1][k] += way[g][j][k];
				}
			}
		}
	}
}
ll calc(ll num, int k){
	if(num == 0) return 1;
	vector<int>vi;
	ll N = num;
	while(N){
		vi.pb(N%10); N/=10;
	}
	reverse(vi.begin(),vi.end());
	int cur = hs[0];
	ll ans = 0;
	rep(i,vi.size()){
		rep(j,vi[i]){
			ans += way[gg[cur][j]][vi.size()-1-i][k];
		}
		cur = gg[cur][vi[i]];
	}
	if(ok[cur][k]) ans++;
	return ans;
}
int main(){
	prepare();
	int t; scanf("%d",&t);
	while(t--){
		ll L,R; int k;
		scanf("%lld%lld%d",&L,&R,&k);
		printf("%lld\n",calc(R,k)-calc(L-1,k));
	}
}