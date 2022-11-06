#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
char s[N],a[N];int f[N];
void sol(){
	scanf("%s",a+1);
	int n=strlen(a+1),m=(n+1)<<1,mx=0;
	while(mx+1<n-mx&&a[mx+1]==a[n-mx])++mx;
	rep(i,0,n)s[i<<1]=a[i],s[i<<1|1]='#';
	s[0]='$';s[m]='@';f[1]=1;
	int r=0,p=0;
	rep(i,2,m-1){
		f[i]=r>i?min(r-i,f[p*2-i]):1;
		while(s[i-f[i]]==s[i+f[i]])++f[i];
		if(i+f[i]>r)r=i+f[i],p=i;
	}
	int ans=-1,x=0;
	rep(i,1,m-1){
		int lp=(i-f[i])/2,rp=(i+f[i])/2;
		if(lp<=mx||rp>=n-mx+1){
			int res=f[i]-1+mx*2-max(mx-lp,rp-n+mx-1)*2;
			if(res>ans)ans=res,x=i;
		}
	}
	int lp=max(x-f[x]+1,mx<<1|1),rp=min(x+f[x]-1,(n-mx)<<1|1);
	if(x-lp<rp-x)rp=x*2-lp;
	if(x-lp>rp-x)lp=x*2-rp;
	rep(i,1,mx)printf("%c",a[i]);
	rep(i,lp,rp)if(s[i]!='#')printf("%c",s[i]);
	rep(i,n-mx+1,n)printf("%c",a[i]);
	printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}