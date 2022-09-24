#include<cstdio>
#include<cmath>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,a[100002],sumg,suml,a1,A,B,C,q;
inline int check(){
	return ceil((double)(a1+sumg)/2.0);
}
inline void cg(re int x,re int y){
	if(x>n)return;
	a[x]>0?sumg-=a[x]:suml+=a[x];
	a[x]+=y;
	a[x]>0?sumg+=a[x]:suml-=a[x];
}
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=2;i<=n;++i){
		if(a[i]>a[i-1])sumg+=a[i]-a[i-1];else suml+=a[i-1]-a[i];
	}
	for(re int i=n;i;--i)a[i]=a[i]-a[i-1];
	a1=a[1];
	printf("%lld\n",check());
	q=read();
	while(q--){
		re int l=read(),r=read(),x=read();
		if(l==1)a1+=x;
		else cg(l,x);
		cg(r+1,-x);
		printf("%lld\n",check());
	}
}