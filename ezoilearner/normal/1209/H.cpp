#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define FR first
#define SE second

int n;ld L;
#define Maxn 400010
ld len[Maxn],sp[Maxn];int cnt=0;

ld r[Maxn];
ld Ans=0.0;
ld sum[Maxn];

typedef pair<ld,int> pli;
pli seq[Maxn];

ld mn[Maxn<<2],tag[Maxn<<2];
void make_tag(int k,ld t){
	tag[k]+=t;mn[k]+=t;
}
void push_down(int k){
	make_tag(k<<1,tag[k]);make_tag(k<<1|1,tag[k]);tag[k]=0.0;
}

#define ls k<<1
#define rs k<<1|1
void build(int k,int l,int r){
	if(l==r){
		mn[k]=sum[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);build(rs,mid+1,r);
	mn[k]=min(mn[ls],mn[rs]);
}
ld query(int k,int l,int r,int L,int R){
	if(l==L&&r==R)return mn[k];
	push_down(k);
	int mid=(l+r)>>1;
	if(R<=mid)return query(ls,l,mid,L,R);
	else if(mid<L)return query(rs,mid+1,r,L,R);
	else return min(query(ls,l,mid,L,mid),query(rs,mid+1,r,mid+1,R));
}
void Add(int k,int l,int r,int L,int R,ld t){
	if(l==L&&r==R){
		make_tag(k,t);
		return;
	}
	push_down(k);
	int mid=(l+r)>>1;
	if(R<=mid)Add(ls,l,mid,L,R,t);
	else if(mid<L)Add(rs,mid+1,r,L,R,t);
	else{
		Add(ls,l,mid,L,mid,t);
		Add(rs,mid+1,r,mid+1,R,t);
	}
	mn[k]=min(mn[ls],mn[rs]);
}

int main(){
	scanf("%d%Lf",&n,&L);
	ld pre=0.0;int x,y;
	rep(i,1,n){
		scanf("%d%d%Lf",&x,&y,&sp[cnt+2]);
		len[++cnt]=x-pre;
		len[++cnt]=y-x;
		pre=y;
	}
	len[++cnt]=L-pre;sp[cnt]=0;
	rep(i,1,cnt){
		sum[i]=sum[i-1];
		sum[i]-=len[i];
		double R;if(sp[i]>0.0)R=len[i]/sp[i];else R=L;
		Ans+=-R;
		r[i]=R-len[i]/(sp[i]+2);
		sum[i]-=(-R)*(sp[i]+1);
		seq[i]=pli(sp[i]+1,i);
	}
	build(1,1,cnt);
	sort(seq+1,seq+cnt+1);
	rep(t,1,cnt){
		int i=seq[t].SE;
		ld tmp=min(query(1,1,cnt,i,cnt),r[i]*(sp[i]+1));
		Ans+=tmp/(sp[i]+1);
		Add(1,1,cnt,i,cnt,-tmp);
	}
	Ans=-Ans;
	printf("%.12Lf\n",Ans);
	return 0;
}