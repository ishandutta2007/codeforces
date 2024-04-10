#include <bits/stdc++.h>
#define MAXN 200010
#define LL long long

const LL P=1000000007;

int n,m,q,sizew;
LL a[MAXN];
LL v0[MAXN];
LL s[MAXN<<2],s2[MAXN<<2],s3[MAXN<<2];

LL getS(int x,int cl,int cr,int l,int r){
	if(l<=cl && cr<=r) return s[x];
	int mid=(cl+cr)>>1;
	if(r<=mid) return getS(x<<1,cl,mid,l,r);
	if(l>mid) return getS(x<<1|1,mid+1,cr,l,r);
	return getS(x<<1,cl,mid,l,r)+getS(x<<1|1,mid+1,cr,l,r);
}

LL getS2(int x,int cl,int cr,int l,int r){
	if(l<=cl && cr<=r) return s2[x];
	int mid=(cl+cr)>>1;
	if(r<=mid) return getS2(x<<1,cl,mid,l,r);
	if(l>mid) return getS2(x<<1|1,mid+1,cr,l,r);
	return (getS2(x<<1,cl,mid,l,r)+getS2(x<<1|1,mid+1,cr,l,r))%P;
}

LL getS3(int x,int cl,int cr,int l,int r){
	if(l<=cl && cr<=r) return s3[x];
	int mid=(cl+cr)>>1;
	if(r<=mid) return getS3(x<<1,cl,mid,l,r);
	if(l>mid) return getS3(x<<1|1,mid+1,cr,l,r);
	return (getS3(x<<1,cl,mid,l,r)+getS3(x<<1|1,mid+1,cr,l,r))%P;
}

void modify(int x,int cl,int cr,int pos,LL v){
	if(cl==cr){
		s[x]=v;
		s2[x]=v*pos%P;
		s3[x]=v*a[cl]%P;
		return;
	}
	int mid=(cl+cr)>>1;
	if(pos<=mid) modify(x<<1,cl,mid,pos,v);
	else modify(x<<1|1,mid+1,cr,pos,v);
	s[x]=s[x<<1]+s[x<<1|1];
	s2[x]=(s2[x<<1]+s2[x<<1|1])%P;
	s3[x]=(s3[x<<1]+s3[x<<1|1])%P;
}

void init(){
	for(sizew=1;sizew<n;sizew<<=1);
	for(int i=1;i<=n;i++){
		s[sizew+i-1]=v0[i];
		s2[sizew+i-1]=v0[i]*i%P;
		s3[sizew+i-1]=v0[i]*a[i]%P;
	}
	for(int i=sizew-1;i;i--){
		s[i]=s[i<<1]+s[i<<1|1];
		s2[i]=(s2[i<<1]+s2[i<<1|1])%P;
		s3[i]=(s3[i<<1]+s3[i<<1|1])%P;
	}
}

int res;
void find(int x,int cl,int cr,int l,int r,LL &lim){
	if(l<=cl && cr<=r){
		if(s[x]<lim){
			lim-=s[x];
		}else if(cl==cr){
			res=cl;
		}else{
			int mid=(cl+cr)>>1;
			if(s[x<<1]>=lim) find(x<<1,cl,mid,l,r,lim);
			else find(x<<1|1,mid+1,cr,l,r,lim-=s[x<<1]);
		}
		return;
	}
	int mid=(cl+cr)>>1;
	if(r<=mid) find(x<<1,cl,mid,l,r,lim);
	else if(l>mid) find(x<<1|1,mid+1,cr,l,r,lim);
	else{
		find(x<<1,cl,mid,l,r,lim);
		if(res) return;
		find(x<<1|1,mid+1,cr,l,r,lim);
	}
}

LL query(int l,int r){
	LL sl=getS(1,1,sizew,l,r),sl2=(sl+1)/2;
	res=0;
	find(1,1,sizew,l,r,sl2);
	LL pos=a[res]-res;
	LL t1=getS(1,1,sizew,l,res)%P,t2=getS2(1,1,sizew,l,res),t3=getS3(1,1,sizew,l,res);
	LL ans=0;
	(ans+=t1*pos+t2-t3)%=P;
	t1=getS(1,1,sizew,res,r)%P,t2=getS2(1,1,sizew,res,r),t3=getS3(1,1,sizew,res,r);
	(ans+=t3-t1*pos-t2)%=P;
	if(ans<0) ans+=P;
	return ans;
}

int main(){
#ifdef DEBUG
	freopen("C.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++) scanf("%lld",v0+i);
	init();
	while(m--){
		int x;
		scanf("%d",&x);
		if(x<0){
			int y;
			scanf("%d",&y);
			x=-x;
			modify(1,1,sizew,x,y);
		}else{
			int r;
			scanf("%d",&r);
			printf("%lld\n",query(x,r));
		}
	}
}