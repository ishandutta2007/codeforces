#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)

#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define ll long long
ll sum[N],y;
int n,m,i,typ,x,pos,ans,mx[N],a[N],tg[N];
void build(int k,int l,int r){
	if(l==r){
		sum[k]=mx[k]=a[l];return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	sum[k]=sum[ls]+sum[rs];
	mx[k]=max(mx[ls],mx[rs]);
}
void down(int k,int l,int r){
	if(tg[k]){
		tg[ls]=tg[k];
		tg[rs]=tg[k];
		mx[ls]=tg[k];
		mx[rs]=tg[k];
		sum[ls]=1ll*(mid-l+1)*tg[k];
		sum[rs]=1ll*(r-mid)*tg[k];
		tg[k]=0;
	}
}
void Tm(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){
		if(mx[k]<=v){
			tg[k]=v;
			sum[k]=1ll*(r-l+1)*v;
			mx[k]=v;
			return ;
		}
		if(l==r)return ;
		down(k,l,r);
		if(mx[rs]<v)Tm(ls,l,mid,x,y,v);
		Tm(rs,mid+1,r,x,y,v);
		sum[k]=sum[ls]+sum[rs];
		mx[k]=max(mx[ls],mx[rs]);
		return ;
	}
	if(y<l||r<x)return ;
	down(k,l,r);
	Tm(ls,l,mid,x,y,v);Tm(rs,mid+1,r,x,y,v);
	sum[k]=sum[ls]+sum[rs];
	mx[k]=max(mx[ls],mx[rs]);
}
int find(int k,int l,int r,ll y){
//	cout<<k<<" "<<l<<" "<<r<<"\n";
	if(l==r){
		if(mx[k]<=y)return l;
		return l+1;
	}
	down(k,l,r);
	if(mx[rs]<=y)return find(ls,l,mid,y);
	return find(rs,mid+1,r,y);
}
int FIND(int k,int l,int r,int x,ll &y){
//	cout<<k<<" "<<l<<" "<<r<<"\n";
	if(r<x)return n+1;
	if(x<=l){
		if(sum[k]<=y)return y-=sum[k],n+1;
		if(l==r)return l;
		down(k,l,r);
		if(sum[ls]<=y)return FIND(rs,mid+1,r,x,y-=sum[ls]);
		return FIND(ls,l,mid,x,y);
	}
	down(k,l,r);
	int f1=FIND(ls,l,mid,x,y);
	if(f1!=n+1)return f1;
	return FIND(rs,mid+1,r,x,y);
}
ll SUM(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return sum[k];
	if(x>r||y<l)return 0;down(k,l,r);
	return SUM(ls,l,mid,x,y)+SUM(rs,mid+1,r,x,y);
}
signed main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>a[i];
	}
	build(1,1,n);
	while(m--){
		cin>>typ;
		if(typ==1){
			cin>>x>>y;
			Tm(1,1,n,1,x,y);
		}
		else{
			cin>>x>>y;
			if(x!=1)y+=SUM(1,1,n,1,x-1);
			i=find(1,1,n,y);
			ans=0;
			for(;;){
				if(i>n)break;
				pos=FIND(1,1,n,i,y);
				ans+=pos-i;
				if(pos>n)break;
				i=find(1,1,n,y);
			}
			printf("%d\n",ans-x+1);
		}
	}
}