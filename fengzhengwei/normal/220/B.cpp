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
int n,m,B;
const int xx=1e5+5;
int a[xx];
int bel(int x){return (x-1)/B+1;}
struct node
{
	int l,r,id;
	bool operator<(const node&w)const{return bel(l)==bel(w.l)?bel(l)&1?r<w.r:r>w.r:l<w.l;}
}e[xx];
int ans;
int lsh[xx],t[xx],res[xx];
void add(int x)
{
	if(t[a[x]]==lsh[a[x]])ans--;
	t[a[x]]++;
	if(t[a[x]]==lsh[a[x]])ans++;
}
void erase(int x)
{
	if(t[a[x]]==lsh[a[x]])ans--;
	t[a[x]]--;
	if(t[a[x]]==lsh[a[x]])ans++;
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=lsh[i]=read(),ans+=(a[i]==0);
	B=sqrt(m);
	sort(lsh+1,lsh+n+1);
	int tot=unique(lsh+1,lsh+n+1)-lsh-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+tot+1,a[i])-lsh;
	for(int i=1;i<=m;i++)e[i].id=i,e[i].l=read(),e[i].r=read();
	sort(e+1,e+m+1);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<e[i].r)add(++r);
		while(l>e[i].l)add(--l);
		while(r>e[i].r)erase(r--);
		while(l<e[i].l)erase(l++);
		res[e[i].id]=ans;
	}
	for(int i=1;i<=m;i++)cout<<res[i]<<"\n";
	return 0;
}