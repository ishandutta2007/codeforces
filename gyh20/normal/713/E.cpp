#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,L,a[200002],b[100002],mx,f[100002];
inline int ck(re int x){
	f[1]=0;
	for(re int i=2;i<=n;++i){
		f[i]=0;
		if(f[i-1]+x>=b[i]-1)f[i]=b[i];
		if(f[i-1]>=b[i]-1)f[i]=b[i]+x;
		if(f[i-2]+x>=b[i]-1&&i!=2)f[i]=max(f[i],b[i-1]+x);
	}
	if(f[n]>=L-x-1)return 1;
	f[1]=x;
	for(re int i=2;i<=n;++i){
		f[i]=0;
		if(f[i-1]+x>=b[i]-1)f[i]=b[i];
		if(f[i-1]>=b[i]-1)f[i]=b[i]+x;
		if(f[i-2]+x>=b[i]-1&&i>2)f[i]=max(f[i],b[i-1]+x);
	}
	if(f[n]>=L-1)return 1;
	if(x>=b[2]){
		f[1]=f[2]=x;
		for(re int i=3;i<=n;++i){
			f[i]=0;
			if(f[i-1]+x>=b[i]-1)f[i]=b[i];
			if(f[i-1]>=b[i]-1)f[i]=b[i]+x;
			if(f[i-2]+x>=b[i]-1)f[i]=max(f[i],b[i-1]+x);
		}
		if(f[n]>=L-1-(x-b[2]))return 1;
	}
	return 0;
}
int main(){
	L=read(),n=read();
	if(n==1)return printf("%d",L-1),0;
	for(re int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+n+1);
	for(re int i=1;i<=n;++i)a[i+n]=a[i]+L;
	for(re int i=1;i<=n;++i)mx=max(mx,a[i+1]-a[i]);
	for(re int i=1;i<=n;++i)
		if(a[i+1]-a[i]==mx){
			for(re int j=1;j<=n;++j)b[j]=a[j+i]-a[i+1];
			break;
		}
	re int l=0,r=mx-1,pos=mx;
	while(l<=r){
		re int mid=l+r>>1;
		if(ck(mid))pos=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",pos);
}