//                                               
//                                                           
//                                                            
//                                                               
//                                                              
//                                                             
//                                               
#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int mod=998244353;
int n,m1,m2,pl[N],pr[N],cf[N],dp[N];
char s[N],L[N],R[N];
void Z(char *s,int n,int *z){
	z[1]=n;
	for(int i=2,l=0,r=1;i<=n;++i){
		if(i<=r)z[i]=min(r-i+1,z[i-l+1]);
		else z[i]=0;
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1])++z[i];
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
}
void exkmp(char *s,char *t,int n,int m,int *p){
	static int z[N];
	Z(t,m,z);
	for(int i=1,l=0,r=0;i<=n;++i){
		if(i<=r)p[i]=min(r-i+1,z[i-l+1]);
		while(i+p[i]<=n&&s[i+p[i]]==t[p[i]+1])++p[i];
		if(i+p[i]-1>r)l=i,r=i+p[i]-1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1)>>(L+1)>>(R+1);
	n=strlen(s+1);
	m1=strlen(L+1);
	m2=strlen(R+1);
	exkmp(s,L,n,m1,pl);
	exkmp(s,R,n,m2,pr);
	dp[0]=1;
	for(int i=1;i<=n;++i){
		if(s[i]!='0'){
			int l=i+m1;
			if(pl[i]==m1||s[i+pl[i]]>L[pl[i]+1])--l;
			int r=i+m2-2;
			if(pr[i]==m2||s[i+pr[i]]<R[pr[i]+1])++r;
			if(l<=r)cf[l]=(cf[l]+dp[i-1])%mod,cf[r+1]=(cf[r+1]+mod-dp[i-1])%mod;
		}
		else{
			if(m1==1&&L[1]=='0')cf[i]=(cf[i]+dp[i-1])%mod,cf[i+1]=(cf[i+1]+mod-dp[i-1])%mod;	
		}
		cf[i]=(cf[i]+cf[i-1])%mod;
		dp[i]=cf[i];
	}
	cout<<dp[n]<<'\n';
	return 0;
}