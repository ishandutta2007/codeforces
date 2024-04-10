#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,Q;
#define Maxn 200010
#define cout cerr
#define FR first
#define SE second
int tag[Maxn<<2],a[Maxn],mn[Maxn<<2],mx[Maxn<<2];//-1
ll sum[Maxn<<2];
void push_up(int k){
	mn[k]=mn[k<<1|1];mx[k]=mx[k<<1];
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
void make_tag(int k,int l,int r,int t){
	tag[k]=t;
	mx[k]=mn[k]=t;
	sum[k]=1ll*(r-l+1)*t;
}
void push_down(int k,int l,int r){
	int mid=(l+r)>>1;
	if(tag[k]!=-1){
		make_tag(k<<1,l,mid,tag[k]);make_tag(k<<1|1,mid+1,r,tag[k]);
		tag[k]=-1;
	}
}

void BT(int k,int l,int r){
	tag[k]=-1;
	if(l==r){
		mx[k]=mn[k]=a[l];sum[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	BT(k<<1,l,mid);BT(k<<1|1,mid+1,r);
	push_up(k);
}

//pushdown!!!
void Modify(int k,int l,int r,int L,int R,int t){
	if(l==L&&r==R){
		if(l==L&&r==R)make_tag(k,l,r,t);
		return;
	}
	push_down(k,l,r);
	int mid=(l+r)>>1;
	if(R<=mid)Modify(k<<1,l,mid,L,R,t);
	else if(mid<L)Modify(k<<1|1,mid+1,r,L,R,t);
	else{
		Modify(k<<1,l,mid,L,mid,t);
		Modify(k<<1|1,mid+1,r,mid+1,R,t);
	}
	push_up(k);
}

int gao1(int k,int l,int r,int t){
	if(l==r)return l;
	push_down(k,l,r);
	int mid=(l+r)>>1;
	if(mx[k<<1|1]>t)return gao1(k<<1|1,mid+1,r,t);
	else return gao1(k<<1,l,mid,t);
}

int gao3(int k,int l,int r,int t){
	if(l==r)return l;
	push_down(k,l,r);
	int mid=(l+r)>>1;
	if(mn[k<<1]<=t)return gao3(k<<1,l,mid,t);
	return gao3(k<<1|1,mid+1,r,t);
}

int qu(int k,int l,int r,int &t){
	if(l==r){
		if(t>=mx[k]){
			t-=mx[k];
			return l;
		}
		return l-1;
	}
	push_down(k,l,r);
	int mid=(l+r)>>1;
	if(sum[k<<1]<t)return qu(k<<1|1,mid+1,r,t-=sum[k<<1]);
	return qu(k<<1,l,mid,t);
}
pair<bool,int> Qu(int k,int l,int r,int L,int R,int &t){
	if(l==L&&r==R){
		if(t<=sum[k]||R==n)return make_pair(1,qu(k,l,r,t));
		t-=sum[k];
		return make_pair(0,t);
	}
	push_down(k,l,r);
	int mid=(l+r)>>1;
	if(R<=mid)return Qu(k<<1,l,mid,L,R,t);
	else if(mid<L)return Qu(k<<1|1,mid+1,r,L,R,t);
	else{
		pair<bool,int> res=Qu(k<<1,l,mid,L,mid,t);
		if(res.FR)return res;
		return Qu(k<<1|1,mid+1,r,mid+1,R,t);
	}
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);rd(Q);
	for(int i=1;i<=n;++i)rd(a[i]);
	BT(1,1,n);
	int opt,x,y;
	while(Q--){
		rd(opt);rd(x);rd(y);
		if(opt==1){
			int pos=gao1(1,1,n,y);
			if(mx[1]<=y)pos=0;
			if(pos+1<=x)Modify(1,1,n,pos+1,x,y);
		}else{
			int pre=x-1,Ans=0;
			while(true){
				int pos=gao3(1,1,n,y);
				if(mn[1]>y)pos=n+1;
				pos=max(pos,pre+1);
				if(pos==n+1)break;
				int t=Qu(1,1,n,pos,n,y).SE;
				Ans+=t-pos+1;
				pre=t;
			}
			printf("%d\n",Ans);
		}
	}	
	return 0;
}