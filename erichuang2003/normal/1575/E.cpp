#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define int long long
const int _ = 2e5 + 7 , P = 1e9 + 7; vector < pair < int , int > > nxt[_]; int N , K , sz[_] , A[_] , ans;
#define lowbit(x) ((x) & -(x))
struct BIT{
	int arr[_];
	void add(int x , int v){v = (v % P + P) % P; while(x <= N){arr[x] = (arr[x] + v) % P; x += lowbit(x);}}
	int qry(int x){int sum = 0; while(x > 0){sum = (sum + arr[x]) % P; x -= lowbit(x);} return sum;}
}Sum[2] , Num[2];

int nsz , msz , id; bool vis[_];
void csz(int x){vis[x] = 1; ++nsz; for(auto t : nxt[x]){if(!vis[t.fi]) csz(t.fi);} vis[x] = 0;}
int cid(int x){
	int sz = 1 , mx = 0; vis[x] = 1;
	for(auto t : nxt[x]) if(!vis[t.fi]){int v = cid(t.fi); mx = max(mx , v); sz += v;}
	mx = max(mx , nsz - sz); if(mx < msz){msz = mx; id = x;} vis[x] = 0; return sz;
}

void calc(int t , int pre , int cur , int cnt , int sum){
	if(cnt > K - 1) return;
	ans = (ans + sum) % P; vis[t] = 1;
	int C = Num[pre].qry(K - cnt) + Num[pre ^ 1].qry(K - 1 - cnt) , S = Sum[pre].qry(K - cnt) + Sum[pre ^ 1].qry(K - 1 - cnt);
	ans = (ans + S + C * (sum % P)) % P;
	for(auto x : nxt[t]) if(!vis[x.fi]) calc(x.fi , pre , x.se , cnt + (cur != x.se) , sum + A[x.fi]);
	vis[t] = 0;
}
void add(int t , int pre , int cur , int cnt , int flg , int sum){
	Sum[pre].add(cnt , flg * sum); Num[pre].add(cnt , flg); vis[t] = 1;
	for(auto x : nxt[t]) if(!vis[x.fi]) add(x.fi , pre , x.se , cnt + (cur != x.se) , flg , sum + A[x.fi]);
	vis[t] = 0;
}

void solve(int x){
	nsz = 0; msz = 1e9; csz(x); cid(x); x = id; vis[x] = 1; ans = (ans + A[x]) % P;
	for(auto t : nxt[x]) if(!vis[t.fi]){calc(t.fi , t.se , t.se , 0 , A[t.fi] + A[x]); add(t.fi , t.se , t.se , 1 , 1 , A[t.fi]);}
	for(auto t : nxt[x]) if(!vis[t.fi]) add(t.fi , t.se , t.se , 1 , -1 , A[t.fi]);
	for(auto t : nxt[x]) if(!vis[t.fi]) solve(t.fi);
}
	
signed main(){
	ios::sync_with_stdio(0); cin >> N >> K; ++K; for(int i = 1 ; i <= N ; ++i) cin >> A[i];
	for(int i = 1 ; i < N ; ++i){int p , q , r; cin >> p >> q >> r; nxt[p].push_back(make_pair(q , r)); nxt[q].push_back(make_pair(p , r));}
	solve(1); cout << ans; return 0;
}