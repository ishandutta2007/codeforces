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


int32_t main(){
	fastio;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
	}
	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
	}
	string ans="";
	for(int i=0;i<n-1;i++)ans+='U';
	for(int j=0;j<m-1;j++)ans+='L';
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(i%2==0)ans+='R';
			else ans+='L';
		}
		if(i!=n-1)ans+='D';
	}
	cout<<ans.size()<<endl;
	cout<< ans<<endl;
	
	
}