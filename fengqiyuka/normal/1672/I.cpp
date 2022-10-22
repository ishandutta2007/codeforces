#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x)&(-(x)))

const int N=5e5+100,lim=1e9;

struct node{
	int x,c,s;
};
struct tree{
	int l,r,lc,rc,c1;node c;
};

int mymax(int x,int y) {return (x>y?x:y);}

set<int>::iterator iter;int n;
struct seg{
	set<int> S;
	tree tr[2*N];int a[N],ID[N],len=0;
	int Tree[N];
	
	void add(int x,int c){
		for(int i=x;i<=n;i+=lowbit(i)) Tree[i]+=c;
		return ;
	}
	int Find(int x){
		int Sum=0;
		for(int i=x;i;i-=lowbit(i)) Sum+=Tree[i];
		return Sum;
	}
	void build(int l,int r){
		int now=++len;
		tr[now].l=l;tr[now].r=r;
		tr[now].lc=tr[now].rc=-1;
		tr[now].c.c=tr[now].c.s=tr[now].c1=0;
		if(l<r){
			int mid=(l+r)>>1;
			tr[now].lc=len+1;build(l,mid);
			tr[now].rc=len+1;build(mid+1,r);
		}
		else tr[now].c.x=l;
	}
	void Change(int now,int k,int c){
		if(tr[now].l==tr[now].r) {tr[now].c1=c;return ;}
		int mid=(tr[now].l+tr[now].r)>>1;
		int lc=tr[now].lc,rc=tr[now].rc;
		if(k<=mid) Change(lc,k,c);
		else Change(rc,k,c);
		tr[now].c1=mymax(tr[lc].c1,tr[rc].c1);
	}
	int findmax(int now,int l,int r){
		if(tr[now].l==l&&r==tr[now].r) return tr[now].c1;
		int mid=(tr[now].l+tr[now].r)>>1;
		int lc=tr[now].lc,rc=tr[now].rc;
		if(r<=mid) return findmax(lc,l,r);
		else if(mid<l) return findmax(rc,l,r);
		else return mymax(findmax(lc,l,mid),findmax(rc,mid+1,r));
	}
	void Add(int now,int k,int c){
		if(tr[now].l==tr[now].r) {tr[now].c.c+=c;tr[now].c.s+=c;return ;}
		int mid=(tr[now].l+tr[now].r)>>1;
		int lc=tr[now].lc,rc=tr[now].rc;
		if(k<=mid) Add(lc,k,c);
		else Add(rc,k,c);
		if(tr[lc].c.c<tr[lc].c.s+tr[rc].c.c) tr[now].c=tr[lc].c;
		else tr[now].c=tr[rc].c,tr[now].c.c+=tr[lc].c.s;
		tr[now].c.s=tr[lc].c.s+tr[rc].c.s;
	}
	
	void Insert(int x){
		int L,R;
		iter=S.lower_bound(a[x]);R=(*iter);
		iter--;L=(*iter);
		int t=Find(a[x])-Find(L);
		Add(1,ID[R],t);Add(1,x,-t);
		Change(1,a[x],-lim);
		S.insert(a[x]);
		Add(1,x,-lim);Add(1,x+1,lim);
		Change(1,a[x],-1e9);
	}
	void Delete(int x){
		int L,R;
		S.erase(a[x]);
		iter=S.lower_bound(a[x]);R=(*iter);
		iter--;L=(*iter);
		add(a[x],1);
		int t=Find(a[x])-Find(L);
		Add(1,ID[R],-t);Add(1,x,t);
		Add(1,x,lim);Add(1,x+1,-lim);
		Change(1,a[x],-1e9);
	}
	void findnex(int x){
		int L,R;
		iter=S.lower_bound(a[x]+1);R=(*iter);
		iter--;iter--;L=(*iter);
		int t=findmax(1,a[x],R-1);
		while(t>ID[L]){
			Insert(t);R=a[t];
			t=findmax(1,a[x],R-1);
		}
	}
	
}A,B;

int a[N],ID[N];

int main()
{
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),ID[a[i]]=i;
	a[n+1]=ID[n+1]=n+1;
	
	A.build(0,n+1);B.build(0,n+1);//care
	for(int i=1;i<=n;i++){
		if(a[i]>=i){
			A.a[i]=a[i];A.ID[a[i]]=i;
			A.Change(1,a[i],i);
			A.Add(1,i,a[i]-i);A.Add(1,i+1,i-a[i]);
		}
		else{
			B.a[n-i+1]=n-a[i]+1;
			B.ID[n-a[i]+1]=n-i+1;
			B.Change(1,n-a[i]+1,n-i+1);
			B.Add(1,n-i+1,i-a[i]);
			B.Add(1,n-i+2,a[i]-i);
		}
	}
	A.a[0]=B.a[0]=A.ID[0]=B.ID[0]=0;
	A.a[n+1]=B.a[n+1]=A.ID[n+1]=B.ID[n+1]=n+1;
	
	A.S.insert(0);A.S.insert(n+1);
	B.S.insert(0);B.S.insert(n+1);
	A.Add(1,0,lim);B.Add(1,0,lim);
	A.findnex(0);
	B.findnex(0);
	
	int Ans=0;
	for(int i=1;i<=n;i++){
		if(A.tr[1].c.c<B.tr[1].c.c){
			Ans=mymax(Ans,A.tr[1].c.c);
			int x=A.tr[1].c.x;
			A.findnex(x);
			iter=B.S.lower_bound(n-A.a[x]+1);
			int y=B.ID[(*iter)];
			B.Add(1,y,-1);B.Add(1,n-x+1,1);
			B.add(n-A.a[x]+1,1);
			A.Delete(x);
		}
		else{
			Ans=mymax(Ans,B.tr[1].c.c);
			int x=B.tr[1].c.x;
			B.findnex(x);
			iter=A.S.lower_bound(n-B.a[x]+1);
			int y=A.ID[(*iter)];
			A.Add(1,y,-1);A.Add(1,n-x+1,1);
			A.add(n-B.a[x]+1,1);
			B.Delete(x);
		}
	}
	
	printf("%d\n",Ans);
	
	return 0;
}