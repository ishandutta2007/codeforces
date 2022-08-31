#include<bits/stdc++.h>
#define re register
#define ull unsigned long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct node{
	ull a[5];
	inline void clr(){memset(a,0,sizeof(a));}
	node operator +(const node A)const{
		node c;
		for(re int i=0;i<=4;++i)c.a[i]=a[i]+A.a[i];
		return c; 
	}
	node operator -(const node A)const{
		node c;
		for(re int i=0;i<=4;++i)c.a[i]=a[i]-A.a[i];
		return c; 
	}
	node operator *(const ull A)const{
		node c;
		for(re int i=0;i<=4;++i)c.a[i]=a[i]*A;
		return c;
	}
	node operator*(const node A)const{
		node c;c.clr();
		for(re int i=0;i<=4;++i)
			for(re int j=0;j<=4;++j)
				if(i+j<=4)c.a[i+j]+=a[i]*A.a[j];
				else c.a[i+j-5]+=a[i]*A.a[j];
		return c;
	}
}W[12],f[100002],tmp[12];
inline node ksm(node x,int y){
	node tmp;tmp.clr(),tmp.a[0]=1;
	while(y){
		if(y&1)tmp=tmp*x;
		x=x*x,y>>=1;
	}return tmp;
}
const ull i5=14757395258967641293ull;
int n,m;
int main(){
	n=read(),m=1e5,W[0].a[0]=1,W[1].a[3]=-1;
	for(re int i=2;i<=10;++i)W[i]=W[i-1]*W[1];
	for(re int i=1;i<=n;++i)++f[read()].a[0];
	for(re int i=1;i<m;i*=10)
		for(re int j=0;j<m;++j)
			if((j/i)%10==0){
				for(re int k=0;k<10;++k)tmp[k]=f[j+k*i],f[j+k*i].clr();
				for(re int k=0;k<10;++k)
					for(re int l=0;l<10;++l)
						f[j+l*i]=f[j+l*i]+tmp[k]*W[k*l%10];
			}
	for(re int i=0;i<m;++i)f[i]=ksm(f[i],n);
	for(re int i=1;i<m;i*=10)
		for(re int j=0;j<m;++j)
			if((j/i)%10==0){
				for(re int k=0;k<10;++k)tmp[k]=f[j+k*i],f[j+k*i].clr();
				for(re int k=0;k<10;++k)
					for(re int l=0;l<10;++l)
						f[j+l*i]=f[j+l*i]+tmp[k]*W[(10-1)*k*l%10];
			}
	for(re int i=0;i<n;++i){
		re ull tmp=f[i].a[0]-f[i].a[1];tmp*=i5*i5*i5*i5*i5;
		printf("%llu\n",(tmp/32)%(1ll<<58));
	}
}