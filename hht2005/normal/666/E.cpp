#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int sum[N],sa[N],rk[N],t[N],ht[N],f[N],fa[N],ans[N],C[N],n,m;
int rt[N],ls[N*20],rs[N*20],Max[N*20],cnt[N*20],Maxx,Cnt,tot;
struct node {
	int l,r,x,id;
	node(){}
	node(int L,int R,int X,int Id) {
		l=L,r=R,x=X,id=Id;
	}
};
vector<node>q[N];
vector<int>mer[N];
void updata(int p) {
	if(Max[ls[p]]>=Max[rs[p]]) {
		Max[p]=Max[ls[p]];
		cnt[p]=cnt[ls[p]];
	} else {
		Max[p]=Max[rs[p]];
		cnt[p]=cnt[rs[p]];
	}
}
void add(int &p,int l,int r,int x) {
	if(x==0)return;
	if(!p)p=++tot;
	if(l==r) {
		Max[p]++;
		cnt[p]=l;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(ls[p],l,mid,x);
	else add(rs[p],mid+1,r,x);
	updata(p);
}
int merge(int x,int y,int l,int r) {
	if(!x||!y)return x+y;
	if(l==r) {
		Max[x]+=Max[y];
		return x;
	}
	int mid=(l+r)>>1;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	updata(x);
	return x;
}
void qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y) {
		if(Maxx<Max[p]) {
			Maxx=Max[p];
			Cnt=cnt[p];
		}
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)qry(ls[p],l,mid,x,y);
	if(y>mid)qry(rs[p],mid+1,r,x,y);
}
bool cmp(int a,int b,int c) {
	return a+c<=n&&b+c<=n&&t[a]==t[b]&&t[a+c]==t[b+c];
}
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void Merge(int x,int y) {
	// cerr<<x<<' '<<y<<endl;
	int p=get(x),q=get(y);
	fa[q]=p;
	rt[p]=merge(rt[p],rt[q],1,m);
}
int main() {
	int Q;
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		s[++n]='z'+1;
		scanf("%s",s+n+1);
		int l=n+1;
		n+=strlen(s+n+1);
		for(int j=l;j<=n;j++)
			f[j]=i;
	}
	for(int i=1;i<=n;i++)sum[rk[i]=s[i]-'a']++;
	for(int i=0;i<=26;i++)sum[i]+=sum[i-1];
	for(int i=n;i>=1;i--)sa[sum[rk[i]]--]=i;
	for(int j=1,p=0,m=26;p<n;j*=2,m=p) {
		p=0;
		for(int i=n-j+1;i<=n;i++)t[++p]=i;
		for(int i=1;i<=n;i++)if(sa[i]>j)t[++p]=sa[i]-j;
		for(int i=0;i<=m;i++)sum[i]=0;
		for(int i=1;i<=n;i++)sum[rk[i]]++;
		for(int i=1;i<=m;i++)sum[i]+=sum[i-1];
		for(int i=n;i>=1;i--)sa[sum[rk[t[i]]]--]=t[i];
		memcpy(t,rk,sizeof(rk));
		rk[sa[1]]=p=1;
		for(int i=2;i<=n;i++)rk[sa[i]]=cmp(sa[i-1],sa[i],j)?p:++p;
	}
	for(int i=1,k=0;i<=n;i++) {
		if(rk[i]==1)continue;
		k?k--:0;
		for(int j=sa[rk[i]-1];s[j+k]==s[i+k];k++);
		ht[rk[i]]=k;
		mer[k].push_back(rk[i]);
	}
	scanf("%d",&Q);
	int a,b,c,d;
	for(int i=1;i<=Q;i++) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		q[d-c+1].push_back(node(a,b,rk[c],i));
	}
	for(int i=1;i<=n;i++)
		fa[i]=i,add(rt[i],1,m,f[sa[i]]);
	for(int i=n;i>=1;i--) {
		for(int j:mer[i])
			Merge(j-1,j);
		for(auto j:q[i]) {
			Cnt=j.l;
			Maxx=0;
			qry(rt[get(j.x)],1,m,j.l,j.r);
			ans[j.id]=Maxx;
			C[j.id]=Cnt;
		}
	}
	for(int i=1;i<=Q;i++)
		printf("%d %d\n",C[i],ans[i]);
	return 0;
}