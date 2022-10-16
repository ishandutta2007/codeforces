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
const int xx=1e6+5;
ll pw(ll x){return x*x;}
ll ans;
int t[xx];
int B;
int bel(int x){return (x-1)/B+1;}
struct node
{
	int l,r,id;
	bool operator<(const node&w)const{return bel(l)==bel(w.l)?bel(l)&1?r<w.r:r>w.r:l<w.l;}
}e[xx];
ll res[xx];
int a[xx];
void add(int x)
{
	ans-=pw(t[a[x]])*a[x];
	t[a[x]]++;
	ans+=pw(t[a[x]])*a[x];
//	cout<<ans<<"ss \n";
}
void erase(int x)
{
	ans-=pw(t[a[x]])*a[x];
	t[a[x]]--;
	ans+=pw(t[a[x]])*a[x];
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	B=sqrt(m);
	for(int i=1;i<=m;i++)e[i].l=read(),e[i].r=read(),e[i].id=i;
	sort(e+1,e+m+1);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<e[i].r)add(++r);
		while(l>e[i].l)add(--l);
		while(r>e[i].r)erase(r--);
		while(l<e[i].l)erase(l++);
		res[e[i].id]=ans;
//		cout<<e[i].id<<"\n";
//		puts("");
	}
	for(int i=1;i<=m;i++)cout<<res[i]<<'\n';
	return 0;
}