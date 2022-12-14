#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define rep(i,l,r) for(int i = (int)l;i<(int)r;i++)
#define td(v) v.begin(),v.end()
#define M   1000000007 // 1e9 + 7
#define MAXN 200100
using namespace std;
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

int can[110];
int a[110];
int p[110];
void solve(){
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		can[i] = 0;
		cin>>a[i];
	}
	rep(i,0,m){cin>>p[i];can[p[i]] = 1;}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>a[j+1] && can[j]){
				swap(a[j],a[j+1]);
			}
		}
	}
	int f=1;
	for(int i=1;i<n;i++){
		if(a[i]<=a[i+1]){
			
		}else f=0;
	}
	if(f)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int32_t main(){
	fastio;
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}