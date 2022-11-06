#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int Mxdt=100000,mod=998244353,INF=1e9;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,k,a[200005],h[200005],l,r;
int main(){
	T=read()+1;
	while(--T){
		n=read();k=read();
		for(int i=1;i<=n;++i)a[i]=read(),++h[a[i]];
		for(int i=1;i<=n;++i)h[i]+=h[i-1];
		int ans=n+1;
		for(int i=0,j=1;i<=n;++i){
			while(j<=n&&h[j]-h[i]<(n-(h[j]-h[i]))+k)++j;
			if(j<=n){
				if(j-i-1<ans){
					l=i+1;r=j;
				}
				ans=min(ans,j-i-1);
			}
		}
		cout<<l<<' '<<r<<"\n";
		int now=1;ans=0;
		for(int i=1;i<=n;++i){
			if(a[i]>=l&&a[i]<=r)++ans;
			else --ans;
			if(ans>0&&k>1){
				ans=0;
				cout<<now<<' '<<i<<"\n";now=i+1;--k;
			}
		}
		cout<<now<<' '<<n<<"\n";
		for(int i=1;i<=n;++i)h[i]=0;
	}
	return 0;
}