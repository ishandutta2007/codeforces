#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define mod 1000000007
int T,n,m,i,j,l,tot;
ll ans;
char s[N];
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
int main(){
	scanf("%s",s+1);
	l=strlen(s+1);
	for(i=1;i<=l;++i){
		if(s[i]=='a')++tot;
		if(s[i]=='b'){
			ans+=ksm(2,tot)-1;
		}
	} 
	cout<<ans%mod;
}