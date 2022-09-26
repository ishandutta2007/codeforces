#include<bits/stdc++.h>
using namespace std;
#define N 2020
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
int n,m,k,pre[N],suf[N],ans;
struct Seg{
	int l,r;
	friend bool operator < (const Seg &a,const Seg &b){
		return a.l+a.r<b.l+b.r;
	}
}a[N];
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		a[i].l=read(),a[i].r=read();
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=n;++i){
		int now=0;
		for(int j=1;j<=m;++j){
			now+=max(0,min(i+k-1,a[j].r)-max(i,a[j].l)+1);
			pre[j]=max(pre[j],now);
		}
	}
	for(int i=n;i>=1;--i){
		int now=0;
		for(int j=m;j>=1;--j){
			now+=max(0,min(i+k-1,a[j].r)-max(i,a[j].l)+1);
			suf[j]=max(suf[j],now);	
		}
	}
	for(int i=0;i<=m;++i){
		ans=max(ans,pre[i]+suf[i+1]);
	}
	printf("%d\n",ans);
	return 0;
}