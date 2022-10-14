/*Author Gary*/
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n,m;
map<mp,char> M;
int main(){
	fastio;
	cin>>n>>m;
	int cnt=0;
	int sm=0;
	rb(i,1,m){
		char t;
		cin>>t;
		if(t=='+'){
			int u,v;
			char c;
			cin>>u>>v>>c;
			M[II(u,v)]=c;
			if(M.find(II(v,u))!=M.end()){
				cnt++;
				if(M[II(v,u)]==c){
					sm++;
				}
			}
		}
		if(t=='-'){
			int u,v;
			cin>>u>>v;
			if(M.find(II(v,u))!=M.end()){
				cnt--;
				if(M[II(v,u)]==M[II(u,v)]){
					sm--;
				}
			}
			M.erase(M.find(II(u,v)));
		}
		if(t=='?'){
			int k;
			cin>>k;
			if(k&1){
				cout<<(cnt? "YES":"NO")<<endl; 
			}
			else{
				cout<<(sm? "YES":"NO")<<endl; 
			}
		}
	}
	return 0;
}