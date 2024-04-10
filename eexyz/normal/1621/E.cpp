#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define int long long
#define db double
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
struct node{
	vector<int>q;
	int sum;
	int L,R;
}u[N];
int v[N],n,m,T,i,ot,x[N],j,vv,qwq[N],OT[N],mn[N<<2],tg[N<<2];
void build(int k,int l,int r){
	tg[k]=0; 
	if(l==r)mn[k]=qwq[l];
	else build(ls,l,mid),build(rs,mid+1,r),mn[k]=min(mn[ls],mn[rs]);
//	cout<<k<<":"<<mn[k]<<"??\n";
}
void down(int k){
	if(tg[k]){
		tg[ls]+=tg[k];
		tg[rs]+=tg[k];
		mn[ls]+=tg[k];
		mn[rs]+=tg[k];
		tg[k]=0;
	}
}
void modify(int k,int l,int r,int x,int y,int v){
//	if(k==1)cout<<x<<' '<<y<<" "<<v<<"\n"; 
	if(x<=l&&r<=y){
		tg[k]+=v;
		mn[k]+=v;
//		cout<<k<<":"<<mn[k]<<"\n";
		return ;
	}
	if(x>r||y<l)return ;
	down(k);
	modify(ls,l,mid,x,y,v),modify(rs,mid+1,r,x,y,v);
	mn[k]=min(mn[ls],mn[rs]);
}
inline bool cmp(node aa,node bb){
	return (aa.sum+(aa.R-aa.L))/(aa.R-aa.L+1)<(bb.sum+(bb.R-bb.L))/(bb.R-bb.L+1);
}
int find(int vv){
	if(v[m]<vv)return m+1;
	int l=1,MID,r=m;
	while(l<r){
		MID=(l+r>>1);
		if(v[MID]<vv)l=MID+1;
		else r=MID;
	}return l;
}
main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;++i)cin>>v[i];
		sort(v+1,v+n+1);
		for(i=1;i<=m;++i)v[i]=v[i+n-m];
		ot=0;
		for(i=1;i<=m;++i){
			cin>>x[i];
			u[i].L=u[i-1].R+1;
			u[i].R=u[i-1].R+x[i];
			for(j=0;j<x[i];++j)cin>>vv,u[i].q.push_back(vv),u[i].sum+=vv;
			ot+=x[i];
		}
		for(i=1;i<=ot;++i)OT[i]=0;
		sort(u+1,u+m+1,cmp);
		j=1;int fl=0;
		for(i=1;i<=m;++i)qwq[i]=-2;
		for(i=1;i<=m;++i){
			int zz=(u[i].sum+(u[i].R-u[i].L))/(u[i].R-u[i].L+1);
			if(zz<=v[i-1])qwq[i-1]=1;
			if(zz<=v[i])qwq[i]=0;
			if(zz<=v[i+1])qwq[i+1]=-1;
			while(v[j]<zz&&j<=m)++j;
//			cout<<zz<<"\n";
		}
		build(1,1,m);
		for(i=1;i<=m;++i){
			for(j=0;j<u[i].q.size();++j){
				int zz=(u[i].sum-u[i].q[j]+u[i].R-u[i].L-1)/(u[i].R-u[i].L);
				int pos=find(zz);
				if(pos>m)continue;
//				cout<<i<<" "<<pos<<" "<<mn[1]<<'\n';
				modify(1,1,m,pos,pos,1e9);
				if(pos<i)modify(1,1,m,pos+1,i,1),OT[u[i].L+j]=mn[1]>=0,modify(1,1,m,pos+1,i,-1);
				if(pos==i)OT[u[i].L+j]=mn[1]>=0;
				if(pos>i)modify(1,1,m,i,pos-1,-1),OT[u[i].L+j]=mn[1]>=0,modify(1,1,m,i,pos-1,1);
//				if(u[i].L==1)cout<<OT[u[i].L+j]<<"\n";
				modify(1,1,m,pos,pos,-1e9);
			}
		}
		for(i=1;i<=ot;++i)cout<<OT[i];cout<<"\n";
		for(i=1;i<=m;++i)u[i].q.clear(),u[i].sum=0;
	}
}