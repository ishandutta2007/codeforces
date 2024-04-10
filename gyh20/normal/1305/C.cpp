#pragma GCC optimize(2,3,4,5)
#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int n,x,y,a[200002],f,m,lst,q[1002],v[1002],tp,lstans[1002];
inline int ksm(re int x,re int y){
	int ans=1;
	while(y){
		if(y&1)ans=ans*x%m;
		x=x*x%m;
		y>>=1;
	}
	return ans;
}
inline int abs(re int x){
	return x>0?x:-x;
}
int main(){
	f=1;
	n=read();m=read();
for(re int i=1;i<=n;++i)a[i]=read();
sort(a+1,a+n+1);
++v[a[1]%m];q[++tp]=a[1]%m;
for(re int i=2;i<=n;++i){
	for(re int j=1;j<=tp;++j)lstans[abs(a[i]-q[j])%m]+=v[q[j]];
	a[i]%=m;
	if(!v[a[i]])q[++tp]=a[i];
	++v[a[i]];
	if(lstans[0])break;
}
for(re int i=0;i<m;++i)f=1ll*f*ksm(i,lstans[i])%m;
printf("%d",f);
}