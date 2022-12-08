#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int Max[N<<2],tag[N<<2],pos[N],tim[N],cnt,n;
void make_tag(int p,int v) {
	tag[p]=Max[p]=v;
}
void push_down(int p) {
	if(tag[p]) {
		make_tag(p<<1,tag[p]);
		make_tag(p<<1|1,tag[p]);
		tag[p]=0;
	}
}
void cover(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y) {
		make_tag(p,v);
		return;
	}
	push_down(p);
	int mid=(l+r)>>1;
	if(x<=mid)cover(p<<1,l,mid,x,y,v);
	if(y>mid)cover(p<<1|1,mid+1,r,x,y,v);
	Max[p]=max(Max[p<<1],Max[p<<1|1]);
}
int qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return Max[p];
	push_down(p);
	int mid=(l+r)>>1,Maxx=0;
	if(x<=mid)Maxx=max(Maxx,qry(p<<1,l,mid,x,y));
	if(y>mid)Maxx=max(Maxx,qry(p<<1|1,mid+1,r,x,y));
	return Maxx;
}
int t[N],l[N],r[N],op[N];
void solve(int p,int l,int r) {
	if(l==r) {
		if(Max[p]==0)pos[++cnt]=l;
		else tim[l]=Max[p];
		return;
	}
	push_down(p);
	int mid=(l+r)>>1;
	solve(p<<1,l,mid);
	solve(p<<1|1,mid+1,r);
}
int main() {
	int q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++) {
		scanf("%d%d",t+i,l+i);
		if(t[i]==0)scanf("%d%d",r+i,op+i);
	}
	for(int i=q;i>=1;i--)
		if(t[i]==0&&op[i]==0)
			cover(1,1,n,l[i],r[i],i);
	memset(tim,0x3f,sizeof(tim));
	solve(1,1,n);
	pos[cnt+1]=n+1;
	for(int i=1;i<=q;i++)
		if(t[i]==0&&op[i]==1) {
			int id=lower_bound(pos+1,pos+cnt+1,l[i])-pos;
			if(pos[id]<=r[i]&&pos[id+1]>r[i])
				tim[pos[id]]=min(tim[pos[id]],max(i,qry(1,1,n,l[i],r[i])));
		}
	for(int i=1;i<=q;i++)
		if(t[i]==1) {
			if(tim[l[i]]>i) {
				puts("N/A");
				continue;
			}
			int id=lower_bound(pos+1,pos+cnt+1,l[i])-pos;
			if(pos[id]==l[i])puts("YES");
			else puts("NO");
		}
	return 0;
}