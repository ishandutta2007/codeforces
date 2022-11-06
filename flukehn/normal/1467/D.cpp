#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##_end=b;i<i##_end;++i)
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int mo=1e9+7;
int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
//template<typename T>
void inc(int &x,int y){x=(x+y>=mo?x+y-mo:x+y);}
int ad(int x,int y){return x+y>=mo?x+y-mo:x+y;}
template<typename T>T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
mt19937 rnd(time(0));

const int N=5011;
int f[N][N],g[N],n,k,q,a[N];

int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	//int T;cin>>T;
	while(cin>>n>>k>>q){
		memset(g,0,sizeof g);
		f[0][0]=f[0][n+1]=0;
		For(i,1,n+1)f[0][i]=1;
		For(i,1,k+1){
			f[i][1]=f[i-1][2];
			f[i][n]=f[i-1][n-1];
			For(j,2,n){
				f[i][j]=ad(f[i-1][j-1],f[i-1][j+1]);
			}
		}
		For(i,1,n+1)cin>>a[i];
		For(i,0,k+1)For(j,1,n+1){
			g[j]=(g[j]+1ll*f[i][j]*f[k-i][j])%mo;
		}
		//For(j,1,n+1)cerr<<"g["<<j<<"]="<<g[j]<<"\n";
		int ans=0;
		For(i,1,n+1)ans=(ans+1ll*g[i]*a[i])%mo;
		while(q--){
			int x,v;
			cin>>x>>v;
			ans=(ans-1ll*g[x]*a[x])%mo;
			a[x]=v;
			ans=(ans+1ll*g[x]*a[x])%mo;
			if(ans<0)ans+=mo;
			cout<<ans<<"\n";
		}

	}
}