#include <bits/stdc++.h>
#define ld long double
#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define rep(i,l,r) for(int i = (int)l;i<(int)r;i++)
#define td(v) v.begin(),v.end()
#define MAXN 100100
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
	
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);

}

int mark[MAXN];
vector<int> g[MAXN];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		mark[i]=0;
		g[i-1].clear();
	}
	vector<int> v(n),f(n);
	
	for(int i=0;i<n;i++){
		cin>>v[i];
		
		f[i] = 0;
		for(int j=0;j<v[i];j++){
			int s;
			cin>>s;
			g[i].pb(s);
			if(f[i])continue;
			else if(!mark[s]){
				mark[s] = 1;
				f[i] = 1;
			}
		}
	
	}
	
	for(int i=0;i<n;i++){
		if(f[i])continue;
		for(int j=1;j<=n;j++){
			if(!mark[j]){
				cout<<"IMPROVE"<<endl;
				cout<<i+1<<" "<<j<<endl;
				return;
			}
		}
	}
	cout<<"OPTIMAL"<<endl;
	
	
}

int32_t main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
}