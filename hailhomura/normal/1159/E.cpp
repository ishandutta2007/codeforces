#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int tc,n,x[MAX],sz[MAX],nw,res[MAX],id,a,b,tree[1<<20];
vector<int> v[MAX],ans;
stack<int> pq;
bool st;

void build(int id,int le,int ri){
	if(le==ri){
		tree[id] = res[le]; return;
	}
	int mid = le+ri>>1;
	build(lc,le,mid), build(rc,mid+1,ri);
	tree[id] = max(tree[lc],tree[rc]);
	return;
}
int que(int id,int le,int ri){
	if(le>b||ri<a)return 0;
	if(le>=a&&ri<=b)return tree[id];
	int mid = le+ri>>1;
	return max(que(lc,le,mid), que(rc,mid+1,ri));
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n;
    	rep(i,1,n+1)v[i].clear(), sz[i] = 0;
    	ans.clear();
    	rep(i,1,n){
    		cin>>x[i];
    		if(x[i]==-1)continue;
    		v[x[i]].pb(-i), sz[i]++;
		}
		rep(i,1,n+1)sort(all(v[i]));
		rep(i,1,n)if(sz[i]==0){
			if(v[i].size()!=0)pq.push(i);
			else sz[i] = -1;
		}
		pq.push(n+1);
		while(!pq.empty()){
			nw = pq.top(), pq.pop();
			if(nw!=n+1)ans.pb(nw);
			for(auto i:v[nw]){
				i*=-1;
				sz[i]--;
				if(sz[i]==0)pq.push(i);
			}
		}
		rep(i,1,n)if(sz[i]==-1)ans.pb(i);
		if(ans.size()!=n)cout<<"-1\n";
		else {
			id = n;
			for(auto i:ans)res[i] = id, --id;
			build(1,1,n);
			st = 1;
			rep(i,1,n){
				if(x[i]==-1||x[i]-1==i)continue;
				a = i+1, b = x[i]-1;
				if(que(1,1,n)>res[i]){st = 0; break;}
			}
			if(!st)cout<<-1;
			else rep(i,1,n)cout<<res[i]<<' '; cout<<endl;
		}
	}
	return 0;
}