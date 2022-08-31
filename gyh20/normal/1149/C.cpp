#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#define re register
using namespace std;
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
inline char nc(){
	re char v=gc();
	while(v!='('&&v!=')')v=gc();
	return v;
}
inline int max(re int x,re int y){
	return x>y?x:y;
}
inline int min(re int x,re int y){
	return x<y?x:y;
}
int n,a[200002],mx[800002],lmx[800002],rdmx[800002],ldmx[800002],rmn[800002],q,sum[800002],mn[800002],mxd[800002];
inline void pu(re int p){
	mx[p]=max(mx[p<<1],max(mx[p<<1|1],max(lmx[p<<1|1]+rdmx[p<<1],ldmx[p<<1|1]-rmn[p<<1])));
	lmx[p]=max(lmx[p<<1],lmx[p<<1|1]+sum[p<<1]);
	rdmx[p]=max(rdmx[p<<1|1],max(sum[p<<1|1]+rdmx[p<<1],mxd[p<<1|1]-rmn[p<<1]));
	ldmx[p]=max(ldmx[p<<1],max(lmx[p<<1|1]+mxd[p<<1],ldmx[p<<1|1]-sum[p<<1]));
	rmn[p]=min(rmn[p<<1|1],rmn[p<<1]+sum[p<<1|1]);
	sum[p]=sum[p<<1]+sum[p<<1|1];
	mxd[p]=max(mxd[p<<1|1]-sum[p<<1],sum[p<<1|1]+mxd[p<<1]);
}
inline void build(re int p,re int l,re int r){
	if(l==r){
		if(a[l]>0)lmx[p]=mx[p]=rdmx[p]=ldmx[p]=sum[p]=mxd[p]=1;
		else rmn[p]=sum[p]=-1,ldmx[p]=rdmx[p]=mx[p]=mxd[p]=1;
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	pu(p);
}


inline void cg(re int p,re int l,re int r,re int x,re int y){
	if(l==r){
		a[l]=y;
		if(a[l]>0)lmx[p]=mx[p]=rdmx[p]=ldmx[p]=sum[p]=mxd[p]=1,rmn[p]=0;
		else rmn[p]=sum[p]=-1,ldmx[p]=rdmx[p]=mx[p]=mxd[p]=1,lmx[p]=0;
//	printf("%d %d %d %d %d %d\n",p,l,r,ldmx[p],sum[p],rmn[p]);
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y);
	else cg(p<<1|1,mid+1,r,x,y);
	pu(p);
//	printf("%d %d %d %d \n",p,l,r,mx[p]);
}
int main(){
	n=read();q=read();n*=2;n-=2;
	for(re int i=1;i<=n;++i)a[i]=(nc()=='(')?1:-1;
	build(1,1,n);
	printnum(mx[1],'\n');
	while(q--){
		re int l=read(),r=read();
		if(a[l]!=a[r]){
			cg(1,1,n,l,-a[l]),cg(1,1,n,r,-a[r]);
		}
		printnum(mx[1],'\n');
	} 
	return pc('o',1);
}