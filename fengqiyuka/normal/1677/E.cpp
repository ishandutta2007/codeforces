#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N],sta[N],tot=0,ID[N],b[N];
bool bz[N];
vector<int> B[N],C[N];

struct tree{
	int l,r,lc,rc,c3,bz3;ll c1,c2,bz1,bz2;
}tr[2*N];int len=0;
void build(int l,int r){
	int now=++len;
	tr[now].l=l;tr[now].r=r;
	tr[now].lc=tr[now].rc=-1;
	tr[now].c1=tr[now].c2=0;
	if(l<r){
		int mid=(l+r)>>1;
		tr[now].lc=len+1;build(l,mid);
		tr[now].rc=len+1;build(mid+1,r);
	}
}
void update(int now,int ti){
	if(tr[now].bz3){
		int lc=tr[now].lc,rc=tr[now].rc;
		
		tr[lc].c1=tr[lc].c1+tr[lc].c2*(tr[now].bz3-tr[lc].c3)+(ll)tr[now].bz1*(tr[lc].r-tr[lc].l+1);
		tr[lc].c2=tr[lc].c2+(ll)tr[now].bz2*(tr[lc].r-tr[lc].l+1);
		tr[lc].c3=tr[now].bz3;
		tr[rc].c1=tr[rc].c1+tr[rc].c2*(tr[now].bz3-tr[rc].c3)+(ll)tr[now].bz1*(tr[rc].r-tr[rc].l+1);
		tr[rc].c2=tr[rc].c2+(ll)tr[now].bz2*(tr[rc].r-tr[rc].l+1);
		tr[rc].c3=tr[now].bz3;
		
		tr[lc].bz1=tr[lc].bz1+tr[lc].bz2*(tr[now].bz3-tr[lc].bz3)+tr[now].bz1;
		tr[lc].bz2+=tr[now].bz2;
		tr[lc].bz3=tr[now].bz3;
		tr[rc].bz1=tr[rc].bz1+tr[rc].bz2*(tr[now].bz3-tr[rc].bz3)+tr[now].bz1;
		tr[rc].bz2+=tr[now].bz2;
		tr[rc].bz3=tr[now].bz3;
		
		tr[now].bz3=tr[now].bz1=tr[now].bz2=0;
	}
}
void Change(int now,int l,int r,int c,int ti){
	if(l>r) return ;
	if(l==tr[now].l&&r==tr[now].r){
		tr[now].c1=tr[now].c1+tr[now].c2*(ti-tr[now].c3)+(ll)c*(tr[now].r-tr[now].l+1);
		tr[now].c2=tr[now].c2+(ll)c*(tr[now].r-tr[now].l+1);
		tr[now].c3=ti;
		tr[now].bz1=tr[now].bz1+tr[now].bz2*(ti-tr[now].bz3)+c;
		tr[now].bz2+=c;
		tr[now].bz3=ti;
		return ;
	}
	update(now,ti);
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) Change(lc,l,r,c,ti);
	else if(mid<l) Change(rc,l,r,c,ti);
	else Change(lc,l,mid,c,ti),Change(rc,mid+1,r,c,ti);
	tr[now].c1=tr[lc].c1+tr[rc].c1+tr[lc].c2*(ti-tr[lc].c3)+tr[rc].c2*(ti-tr[rc].c3);
	tr[now].c2=tr[lc].c2+tr[rc].c2;
	tr[now].c3=ti;
}
ll findans(int now,int l,int r,int ti){
	if(l==tr[now].l&&r==tr[now].r){
		return tr[now].c1+tr[now].c2*(ti-tr[now].c3);
	}
	update(now,ti);
	int mid=(tr[now].l+tr[now].r)>>1;
	int lc=tr[now].lc,rc=tr[now].rc;
	if(r<=mid) return findans(lc,l,r,ti);
	else if(mid<l) return findans(rc,l,r,ti);
	else return findans(lc,l,mid,ti)+findans(rc,mid+1,r,ti);
}

ll Ans[10*N];

struct ques{
	int l,r;
}p[10*N];

int mymin(int x,int y) {return (x<y?x:y);}
int mymax(int x,int y) {return (x>y?x:y);}

int main()
{
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			B[j].push_back(i);
			
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),ID[a[i]]=i;
	
	for(int i=1;i<=q;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
		C[p[i].r].push_back(i);
	}
	
	build(1,n);
	
	for(int i=1;i<=n;i++){
		while(tot&&a[sta[tot]]<a[i]){
			Change(1,sta[tot-1]+1,b[sta[tot]],-1,i);
			bz[sta[tot]]=false;
			tot--;
		}
		sta[++tot]=i;bz[i]=true;
		int Max=0;
		for(auto y:B[a[i]]){
			int t1=ID[y],t2=ID[a[i]/y];
			if(t1<=i&&t2<=i&&y!=a[i]/y) Max=mymax(Max,mymin(t1,t2));
		}
		b[i]=mymax(sta[tot-1],Max);
		Change(1,sta[tot-1]+1,b[i],1,i);
		for(int j=2;j<=n/a[i];j++){
			int x=ID[a[i]*j],t=ID[j];
			if(bz[x]&&t<=i&&j!=a[i]){
				int las=b[x];
				b[x]=mymax(b[x],mymin(x,t));
				Change(1,las+1,b[x],1,i);
			}
		}
		
		for(auto y:C[i])
			Ans[y]=findans(1,p[y].l,p[y].r,i);
	}
	
	for(int i=1;i<=q;i++) printf("%lld\n",Ans[i]);
	
	return 0;
}