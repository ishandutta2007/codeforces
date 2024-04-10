#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m,k;
int a;
int t[2000005];
int sum[2000005];
int B;
struct node
{
	int l,r,id;
	bool operator<(const node&w)const
	{
		return l/B==w.l/B?r<w.r:l<w.l;
	}
}e[200005];
ll res[200005];
ll ans=0;
void add(int x)
{
	ans+=t[sum[x]^k];
	t[sum[x]]++;
}
void del(int x)
{
	t[sum[x]]--;
	ans-=t[sum[x]^k];
}
int main(){
	n=read();
	B=sqrt(n);
	m=read();
	k=read();
	for(int i=1;i<=n;i++)a=read(),sum[i]=sum[i-1]^a;
	for(int i=1;i<=m;i++)
	{
		e[i].l=read()-1;e[i].r=read();
		e[i].id=i;
	}
	sort(e+1,e+m+1);
	int l=0;
	int r=-1;
	for(int i=1;i<=m;i++)
	{
		while(l<e[i].l)del(l++);
		while(l>e[i].l)add(--l);
		while(r<e[i].r)add(++r);
		while(r>e[i].r)del(r--);
		res[e[i].id]=ans;
	}
	for(int i=1;i<=m;i++)cout<<res[i]<<"\n";
	return 0;
}