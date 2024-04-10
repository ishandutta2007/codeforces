#include<bits/stdc++.h>
using namespace std;
#define N 2005
#define pb push_back
#define ll long long
#define pn cout<<"NO\n"
#define py cout<<"YES\n" 
#define mod 1000000007
int T,i,j,d,m,hd,g,n,ee,f1,f2,k,fl,a[N],ans[N],mx,x,y,v,s1[N],st[N],vst[N],dir[4][2];
char s[N][N];
map<pair<int,int> , int>p;
inline gcd(int x,int y){return y?gcd(y,x%y):x;}
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int main(){
	ios::sync_with_stdio(false);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);fl=0;
		for(i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				if(s[i][j]=='0')++fl;
			}
		}
		if(fl)cout<<ksm(2,n*m-fl)<<"\n";
		else cout<<ksm(2,n*m)-1<<"\n"; 
	}
}