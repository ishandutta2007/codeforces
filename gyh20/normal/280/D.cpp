#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,a[100002],lmx[400002],rmx[400002],lmn[400002],rmn[400002],lmxp[400002],rmxp[400002],lmnp[400002],rmnp[400002],sum[400002],mx[400002],mn[400002],mxl[400002],mxr[400002],mnl[400002],mnr[400002],q,rev[400002],num,lp,ans,al,ar,ll[22],rr[22];
inline void pu(re int p){
	if(lmn[p<<1]<=sum[p<<1]+lmn[p<<1|1])lmn[p]=lmn[p<<1],lmnp[p]=lmnp[p<<1];
	else lmn[p]=sum[p<<1]+lmn[p<<1|1],lmnp[p]=lmnp[p<<1|1];
	if(lmx[p<<1]>=sum[p<<1]+lmx[p<<1|1])lmx[p]=lmx[p<<1],lmxp[p]=lmxp[p<<1];
	else lmx[p]=sum[p<<1]+lmx[p<<1|1],lmxp[p]=lmxp[p<<1|1];
	if(rmx[p<<1|1]>=sum[p<<1|1]+rmx[p<<1])rmx[p]=rmx[p<<1|1],rmxp[p]=rmxp[p<<1|1];
	else rmx[p]=sum[p<<1|1]+rmx[p<<1],rmxp[p]=rmxp[p<<1];
	if(rmn[p<<1|1]<=sum[p<<1|1]+rmn[p<<1])rmn[p]=rmn[p<<1|1],rmnp[p]=rmnp[p<<1|1];
	else rmn[p]=sum[p<<1|1]+rmn[p<<1],rmnp[p]=rmnp[p<<1];
	if(mx[p<<1]>=mx[p<<1|1]&&mx[p<<1]>=rmx[p<<1]+lmx[p<<1|1])mx[p]=mx[p<<1],mxl[p]=mxl[p<<1],mxr[p]=mxr[p<<1];
	else if(mx[p<<1|1]>=mx[p<<1]&&mx[p<<1|1]>=rmx[p<<1]+lmx[p<<1|1])mx[p]=mx[p<<1|1],mxl[p]=mxl[p<<1|1],mxr[p]=mxr[p<<1|1];
	else mx[p]=rmx[p<<1]+lmx[p<<1|1],mxl[p]=rmxp[p<<1],mxr[p]=lmxp[p<<1|1];
	if(mn[p<<1]<=mn[p<<1|1]&&mn[p<<1]<=rmn[p<<1]+lmn[p<<1|1])mn[p]=mn[p<<1],mnl[p]=mnl[p<<1],mnr[p]=mnr[p<<1];
	else if(mn[p<<1|1]<=mn[p<<1]&&mn[p<<1|1]<=rmn[p<<1]+lmn[p<<1|1])mn[p]=mn[p<<1|1],mnl[p]=mnl[p<<1|1],mnr[p]=mnr[p<<1|1];
	else mn[p]=rmn[p<<1]+lmn[p<<1|1],mnl[p]=rmnp[p<<1],mnr[p]=lmnp[p<<1|1];
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
inline void RR(re int p){
	swap(lmx[p],lmn[p]),swap(lmxp[p],lmnp[p]),swap(rmx[p],rmn[p]),swap(rmxp[p],rmnp[p]);
	lmx[p]=-lmx[p],lmn[p]=-lmn[p],rmx[p]=-rmx[p],rmn[p]=-rmn[p];
	swap(mx[p],mn[p]),swap(mxl[p],mnl[p]),swap(mxr[p],mnr[p]);
	mx[p]=-mx[p],mn[p]=-mn[p],sum[p]=-sum[p];
	rev[p]^=1;
}
inline void pd(re int p){if(rev[p])RR(p<<1),RR(p<<1|1),rev[p]=0;}
inline void build(re int p,re int l,re int r){
	if(l==r){
		sum[p]=a[l];
		if(a[l]>0)lmx[p]=rmx[p]=mx[p]=a[l],lmxp[p]=rmxp[p]=mxl[p]=mxr[p]=l;
		else lmn[p]=rmn[p]=mn[p]=a[l],lmnp[p]=rmnp[p]=mnl[p]=mnr[p]=l;
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	pu(p);
}
inline void cg(re int p,re int l,re int r,re int x,re int y){
	if(l==r){
		a[l]=y,sum[p]=a[l];
		lmn[p]=rmn[p]=mn[p]=lmx[p]=rmx[p]=mx[p]=lmxp[p]=rmxp[p]=mxl[p]=mxr[p]=lmnp[p]=rmnp[p]=mnl[p]=mnr[p]=0;
		if(a[l]>0)lmx[p]=rmx[p]=mx[p]=a[l],lmxp[p]=rmxp[p]=mxl[p]=mxr[p]=l;
		else lmn[p]=rmn[p]=mn[p]=a[l],lmnp[p]=rmnp[p]=mnl[p]=mnr[p]=l;
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y);
	else cg(p<<1|1,mid+1,r,x,y);
	pu(p);
}
inline void rever(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y){RR(p);return;}
	re int mid=l+r>>1;
	pd(p);
	if(x<=mid)rever(p<<1,l,mid,x,y);
	if(y>mid)rever(p<<1|1,mid+1,r,x,y);
	pu(p);
}
inline void query(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y){
		if(num+lmx[p]>ans)ans=num+lmx[p],al=lp,ar=lmxp[p];
		if(mx[p]>ans)ans=mx[p],al=mxl[p],ar=mxr[p];
		if(num+sum[p]>=rmx[p])num+=sum[p];
		else if(rmx[p])num=rmx[p],lp=rmxp[p];
		else lp=r+1,num=0;
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)query(p<<1,l,mid,x,y);
	if(y>mid)query(p<<1|1,mid+1,r,x,y);
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	build(1,1,n),q=read();
	while(q--){
		if(!read()){
			re int x=read(),y=read();
			cg(1,1,n,x,y);
		}
		else{
			re int l=read(),r=read(),k=read(),cnt=0,kk=0;
			for(re int i=1;i<=k;++i){
				ans=0,num=0,lp=l,al=0,ar=0;
				query(1,1,n,l,r);
				if(ans){
					kk+=ans;
					ll[++cnt]=al,rr[cnt]=ar;
					rever(1,1,n,al,ar);
				}
				else break;
			}
			printf("%d\n",kk);
			for(re int i=1;i<=cnt;++i)rever(1,1,n,ll[i],rr[i]);
		}
	}
}