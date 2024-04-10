#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=2e5+5;
int a[xx];
int B;
int bel(int x){return (x-1)/B+1;}
struct node
{
	int l,r,t,id;
	bool operator<(const node&w)const{return bel(l)==bel(w.l)?bel(r)==bel(w.r)?(bel(l)+bel(r))&1?t>w.t:t<w.t:r<w.r:l<w.l;}
}e[xx];
int uu[xx],vv[xx],lsh[xx];
int l=1,r=0,t=0;
int t1[xx],t2[xx],res[xx];
void add(int x)
{
	t2[t1[a[x]]]--;
	t1[a[x]]++;
	t2[t1[a[x]]]++;
}
void erase(int x)
{
	t2[t1[a[x]]]--;
	t1[a[x]]--;
	t2[t1[a[x]]]++;
}
void c(int x)
{
	if(l<=uu[x]&&uu[x]<=r)
	{
		erase(uu[x]);
		swap(a[uu[x]],vv[x]);
		add(uu[x]);
	}
	else swap(a[uu[x]],vv[x]);
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=lsh[i]=read();
	int cnt=0,tot=0,sss=n;
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1)e[++tot].l=read(),e[tot].r=read(),e[tot].id=tot,e[tot].t=cnt;
		else uu[++cnt]=read(),vv[cnt]=read(),lsh[++sss]=vv[cnt];
	}
	sort(lsh+1,lsh+sss+1);
	sss=unique(lsh+1,lsh+sss+1)-lsh-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+sss+1,a[i])-lsh;
	for(int i=1;i<=cnt;i++)vv[i]=lower_bound(lsh+1,lsh+sss+1,vv[i])-lsh;
	B=pow(n,0.666);
	sort(e+1,e+tot+1);
//	puts("qwewqewqe");
	for(int i=1;i<=tot;i++)
	{
		while(r<e[i].r)add(++r);
		while(l>e[i].l)add(--l);
		while(r>e[i].r)erase(r--);
		while(l<e[i].l)erase(l++);
		while(t<e[i].t)c(++t);
		while(t>e[i].t)c(t--);
		for(int j=1;;j++){if(!t2[j]){res[e[i].id]=j;break;}}
	}
	for(int i=1;i<=tot;i++)cout<<res[i]<<'\n';
	return 0;
}