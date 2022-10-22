#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N],ID[N];
struct tree{
	int l,r,lc,rc,c,bz;
}tr[2*N];int len=0;
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
void add(int now,int c){
	tr[now].c+=c;tr[now].bz+=c;
}
void update(int now){
	if(tr[now].bz){
		add(tr[now].lc,tr[now].bz);
		add(tr[now].rc,tr[now].bz);
		tr[now].bz=0;
	}
}
int mymin(int x,int y) {return (x<y?x:y);}
void Change(int now,int l,int r,int c){
	if(l==tr[now].l&&r==tr[now].r){
		add(now,c);
		return ;
	}
	update(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) Change(lc,l,r,c);
	else if(mid<l) Change(rc,l,r,c);
	else Change(lc,l,mid,c),Change(rc,mid+1,r,c);
	tr[now].c=mymin(tr[lc].c,tr[rc].c);
}
int findans(int now,int k){
	if(tr[now].l==tr[now].r) return tr[now].c;
	update(now);
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(k<=mid) return findans(lc,k);
	else return findans(rc,k);
}
int findmin(int now){
	if(tr[now].l==tr[now].r) return tr[now].l;
	update(now);
	int lc=tr[now].lc,rc=tr[now].rc;
	if(tr[lc].c==tr[now].c) return findmin(tr[now].lc);
	else return findmin(tr[now].rc);
}

int main()
{
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=2*n+1;i++) scanf("%d",&a[i]),ID[a[i]]=i;
	
	build(1,2*n+1);
	for(int i=1;i<=2*n+1;i++){
		if(a[i]<n+1) Change(1,i,2*n+1,-1);
		if(a[i]>n+1) Change(1,i,2*n+1,1);
	}
	
	ll Sum1=0,Sum2=0;
	for(int i=1;i<n+1;i++) Sum1=Sum1+(ID[i+1]-ID[i]+2*n+1)%(2*n+1);
	for(int i=2*n+1;i>n+1;i--) Sum2=Sum2+(ID[i]-ID[i-1]+2*n+1)%(2*n+1);
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		
		if(x>y) swap(x,y);
		
		int t1=0,t2=0;
		if(a[x]<n+1) t1=-1;if(a[x]>n+1) t1=1;
		if(a[y]<n+1) t2=-1;if(a[y]>n+1) t2=1;
		Change(1,x,y-1,t2-t1);
		
		if(a[x]>a[y]) swap(x,y);
		
		if(a[x]<n+1) Sum1=Sum1-(ID[a[x]+1]-ID[a[x]]+2*n+1)%(2*n+1);
		else if(a[x]<=2*n) Sum2=Sum2-(ID[a[x]+1]-ID[a[x]]+2*n+1)%(2*n+1);
		if(a[x]>n+1) Sum2=Sum2-(ID[a[x]]-ID[a[x]-1]+2*n+1)%(2*n+1);
		else if(a[x]>1) Sum1=Sum1-(ID[a[x]]-ID[a[x]-1]+2*n+1)%(2*n+1);
		if(a[y]<n+1) Sum1=Sum1-(ID[a[y]+1]-ID[a[y]]+2*n+1)%(2*n+1);
		else if(a[y]<=2*n) Sum2=Sum2-(ID[a[y]+1]-ID[a[y]]+2*n+1)%(2*n+1);
		if(a[y]!=a[x]+1){
			if(a[y]>n+1) Sum2=Sum2-(ID[a[y]]-ID[a[y]-1]+2*n+1)%(2*n+1);
			else if(a[y]>1) Sum1=Sum1-(ID[a[y]]-ID[a[y]-1]+2*n+1)%(2*n+1);
		}
		
		swap(ID[a[x]],ID[a[y]]);
		
		if(a[x]<n+1) Sum1=Sum1+(ID[a[x]+1]-ID[a[x]]+2*n+1)%(2*n+1);
		else if(a[x]<=2*n) Sum2=Sum2+(ID[a[x]+1]-ID[a[x]]+2*n+1)%(2*n+1);
		if(a[x]>n+1) Sum2=Sum2+(ID[a[x]]-ID[a[x]-1]+2*n+1)%(2*n+1);
		else if(a[x]>1) Sum1=Sum1+(ID[a[x]]-ID[a[x]-1]+2*n+1)%(2*n+1);
		if(a[y]<n+1) Sum1=Sum1+(ID[a[y]+1]-ID[a[y]]+2*n+1)%(2*n+1);
		else if(a[y]<=2*n) Sum2=Sum2+(ID[a[y]+1]-ID[a[y]]+2*n+1)%(2*n+1);
		if(a[y]!=a[x]+1){
			if(a[y]>n+1) Sum2=Sum2+(ID[a[y]]-ID[a[y]-1]+2*n+1)%(2*n+1);
			else if(a[y]>1) Sum1=Sum1+(ID[a[y]]-ID[a[y]-1]+2*n+1)%(2*n+1);
		}
		
		swap(a[x],a[y]);
		
		int t=findans(1,ID[n+1]);
		if(t!=tr[1].c){
			printf("%d\n",findmin(1)%(2*n+1));
		}
		else{
			if(Sum1>2*n){
				printf("%d\n",ID[n+1]%(2*n+1));
			}
			else if(Sum2>2*n){
				printf("%d\n",ID[n+1]-1);
			}
			else printf("-1\n");
		}
	}
	
	return 0;
}