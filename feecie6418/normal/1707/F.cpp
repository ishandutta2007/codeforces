#include<bits/stdc++.h>
using namespace std;
struct Thing{
	int tp,x,w;
}t[17000005];
int n,m,k,w,tn,q,a[10000005],rev[8400005],cntfree[8400005];
int val[8400005],lg2[8400005],allcnt,hasnon0;
//0:0
//1:x=2^w
//2:2^w 
Thing dot(const Thing& x,const Thing& y){
	if(!x.tp)return x;
	if(!y.tp)return y;
	if(x.tp==1&&y.tp==1){
		if(x.x!=y.x)return {0,0,0};
		return {1,x.x,x.w+y.w};
	}
	if(x.tp==1&&y.tp==2)return {1,x.x,x.w+y.w};
	if(x.tp==2&&y.tp==1)return {1,y.x,x.w+y.w};
	return {2,0,x.w+y.w};
}
Thing conv(const Thing& x,const Thing& y){
	if(!x.tp)return x;
	if(!y.tp)return y;
	if(x.tp==1&&y.tp==1)return {1,x.x^y.x,x.w+y.w};
	if(x.tp==1&&y.tp==2)return {2,0,x.w+y.w};
	if(x.tp==2&&y.tp==1)return {2,0,x.w+y.w};
	return {2,0,x.w+y.w+w};
}
void Pushup(int p){
	int dep=lg2[p];
	if(k&(1<<dep))t[p]=dot(t[p*2],t[p*2+1]);
	else t[p]=conv(t[p*2],t[p*2+1]);
}
void upd(int x,int y){
	int z=(x&(tn-1));
	if(cntfree[z])allcnt-=cntfree[z]-1;
	else if(val[z])hasnon0--;
	if(a[x]!=-1)cntfree[z]++,val[z]^=a[x];
	a[x]=y;
	if(a[x]!=-1)cntfree[z]--,val[z]^=a[x];
	int p=tn+rev[z];
	if(cntfree[z])t[p]={2,0,w*(cntfree[z]-1)},allcnt+=cntfree[z]-1;
	else {
		t[p]={1,val[z],0};
		if(val[z])hasnon0++;
	}
	while(p>1)p>>=1,Pushup(p);
}
int Power(int x,int y,int z){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%z;
		x=1ll*x*x%z,y>>=1;
	}
	return ret;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&w),tn=(n&-n),fill(a,a+n,-1),lg2[0]=-1;
	for(int i=0;i<tn;i++){
		rev[i]=((rev[i>>1]>>1)|((i&1)?(tn>>1):0));
		cntfree[i]=(n/tn),t[i+tn]={2,0,w*(cntfree[i]-1)};
		if(i)lg2[i]=lg2[i>>1]+1;
	}
	for(int i=tn-1;i>=1;i--)Pushup(i);
	allcnt=n-tn,hasnon0=0;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),x--,upd(x,y);
	scanf("%d",&q);
	for(int i=1,x,y,z;i<=q;i++){
		scanf("%d%d%d",&x,&y,&z),x--,upd(x,y);
		if(k>=tn){
			if(hasnon0)puts("0");
			else cout<<Power(2,w*allcnt,z)<<'\n';
			continue;
		}
		int s=(t[1].tp==1?t[1].w:t[1].w+w);
		cout<<(t[1].tp?Power(2,s,z):0)<<'\n';
	}
}