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

char s[200100];
int acu[MAXN];
int let[30];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>s[i];acu[i] =0;}
	
	rep(i,0,26){
		let[i] =0;
	}	
	
	for(int i=0;i<m;i++){
		int r;
		cin>>r;
		acu[r]++;
	}
	acu[n]++;
	for(int i=n-1;i>=0;i--){
		acu[i]+=acu[i+1];
	}	
	for(int i=1;i<=n;i++){
		let[s[i]-'a']+=acu[i];
	}
	for(int i=0;i<26;i++)cout<<let[i]<<" ";
	cout<<endl;
		
}

int32_t main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}