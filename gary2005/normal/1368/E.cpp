/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int T;
int n,m;
vector<int>  g[200000+2];
bool vis[200000+2];
void solve(){
	cin>>n>>m;
	rb(i,1,n)
		g[i].clear(),vis[i]=0;
	rb(i,1,m)
		{
			int u,v;
			cin>>u>>v;
			g[v].PB(u);
		}
	vector<int> res;
	rb(i,1,n){
		bool ok=0;
		for(auto it:g[i]){
			if(ok) break;
			if(!vis[it])
			for(auto it2:g[it]){
				if(!vis[it2]){
					ok=1;
					break;	
				}
			}
		}
		if(ok){
			vis[i]=1;
			res.PB(i);
			
		}
//		done:;
	}
	cout<<res.size()<<endl;
	for(auto it:res){
		cout<<it<<" ";
	}
	cout<<endl;
}
int main(){
	fastio;
	cin>>T;
	while(T--) {
//	cout<<"#\n";
	solve();
	}
	return 0;
}

/*
5 7
2 3
1 5
4 5
2 4
3 4
1 2
3 5
*/