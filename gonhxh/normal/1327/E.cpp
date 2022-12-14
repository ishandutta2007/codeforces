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
#define MAXN 200100
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
const int M = 998244353;

int fat[MAXN],inv[MAXN];
int res[MAXN];
int32_t main(){
	fastio;
	fat[0] = inv[0] = 1;
	for(int i=1;i<MAXN;i++){
		fat[i] = (fat[i-1]*i)%M;
		inv[i] = exp(fat[i],M-2,M);
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i==n){
			res[i] = 10LL;
		}else{
			int t = i;
			if(n-t==1){
				res[i] = mod(mod(10LL*mod(2LL*exp(10LL,n-t-1,M),M),M)*9,M);
			}else{
			    int op1 = 	mod(mod(10LL*mod(2LL*exp(10LL,n-t-1,M),M),M)*9,M);
			    int op2 = mod(9LL*9LL*mod(10LL*mod((n-t-1)*exp(10LL,n-t-2,M),M),M),M);
			    res[i] = mod(op1 + op2,M);
			}
			
		}
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
}