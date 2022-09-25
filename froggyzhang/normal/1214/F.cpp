#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int m,n,a[N],b[N],pa[N],pb[N],ans[N];
ll ta[N],tb[N];
int main(){
	m=read(),n=read();
	for(int i=1;i<=n;++i)a[i]=read(),pa[i]=i;
	for(int i=1;i<=n;++i)b[i]=read(),pb[i]=i;
	sort(pa+1,pa+n+1,[&](int i,int j){return a[i]<a[j];});
	sort(pb+1,pb+n+1,[&](int i,int j){return b[i]<b[j];});
	sort(a+1,a+n+1),sort(b+1,b+n+1);
	for(int i=1,j=1,x=1,y=1;i<=n;++i){
		while(x<=n&&a[i]-b[x]>m/2)++x;
		while(j<=n&&b[j]<=a[i])++j;
		while(y<=n&&b[y]-a[i]<=m/2)++y;
		tb[0]-=a[i];
		tb[max(0,x-i+1)]+=a[i];
		tb[max(0,x-i+1)]+=a[i];
		tb[max(0,j-i+1)]-=a[i];
		tb[max(0,j-i+1)]-=a[i];
		tb[max(0,y-i+1)]+=a[i];
		tb[max(0,y-i+1)]+=a[i]+m;
		tb[n-i+2]-=a[i]+m;
	}
	for(int i=1,j=1,x=1,y=1;i<=n;++i){
		while(x<=n&&a[i]-b[x]>m/2)++x;
		while(j<=n&&b[j]<a[i])++j;
		while(y<=n&&b[y]-a[i]<=m/2)++y;
		ta[0]+=a[i]+m;
		ta[max(0,i-y+2)]-=a[i]+m;
		ta[max(0,i-y+2)]-=a[i];
		ta[max(0,i-j+2)]+=a[i];
		ta[max(0,i-j+2)]+=a[i];
		ta[max(0,i-x+2)]-=a[i];
		ta[max(0,i-x+2)]-=a[i];
		ta[i+1]+=a[i];
	}
	
	for(int i=1,j=1,x=1,y=1;i<=n;++i){
		while(x<=n&&b[i]-a[x]>m/2)++x;
		while(j<=n&&a[j]<=b[i])++j;
		while(y<=n&&a[y]-b[i]<=m/2)++y;
		ta[0]-=b[i];
		ta[max(0,x-i+1)]+=b[i];
		ta[max(0,x-i+1)]+=b[i];
		ta[max(0,j-i+1)]-=b[i];
		ta[max(0,j-i+1)]-=b[i];
		ta[max(0,y-i+1)]+=b[i];
		ta[max(0,y-i+1)]+=b[i]+m;
		ta[n-i+2]-=b[i]+m;
	}
	for(int i=1,j=1,x=1,y=1;i<=n;++i){
		while(x<=n&&b[i]-a[x]>m/2)++x;
		while(j<=n&&a[j]<b[i])++j;
		while(y<=n&&a[y]-b[i]<=m/2)++y;
		tb[0]+=b[i]+m;
		tb[max(0,i-y+2)]-=b[i]+m;
		tb[max(0,i-y+2)]-=b[i];
		tb[max(0,i-j+2)]+=b[i];
		tb[max(0,i-j+2)]+=b[i];
		tb[max(0,i-x+2)]-=b[i];
		tb[max(0,i-x+2)]-=b[i];
		tb[i+1]+=b[i];
	}
	for(int i=1;i<=n;++i)ta[i]+=ta[i-1];
	for(int i=1;i<=n;++i)tb[i]+=tb[i-1];
	int pos=1;
	ll mn=tb[1];
	for(int i=2;i<=n;++i){
		ll w=tb[i]+ta[n-i+2];
		if(w<mn)mn=w,pos=i;	
	}
	printf("%lld\n",mn);
	for(int i=1;i<=n;++i){
		ans[pa[i]]=pb[(i+pos-2)%n+1];	
	}
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}