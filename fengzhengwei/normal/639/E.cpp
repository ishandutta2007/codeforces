#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=2e5+5;
struct node{ll p,t;bool operator<(const node&w)const{return p*w.t>w.p*t;};}e[xx];
struct nod{ll p,mnt,mxt;bool operator<(const nod&w)const{return p<w.p;};}w[xx];
ll mnt[xx],mxt[xx],T[xx];
bool check(double c)
{
	double Mn=1e64;
	int j=n;
	for(int i=n;i>=1;i--)
	{
		while(j>=1&&w[j].p>w[i].p)Mn=min(Mn,w[j].p*(1-c*w[j].mxt/T[n])),j--;
//		cerr<<i<<" "<<w[i].p*(1-c*w[i].mnt/T[n])<<" "<<Mn<<" "<<(1-c*w[i].mnt/T[n])<<"\n";
		if(w[i].p*(1-c*w[i].mnt/T[n])>Mn)return 0;
	}
//	cout<<Mn<<"\n";
	return 1;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)e[i].p=read();
	for(int i=1;i<=n;i++)e[i].t=read();
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)T[i]=T[i-1]+e[i].t;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j+1<=n&&e[i].p*e[j+1].t==e[j+1].p*e[i].t)j++;
		ll Mn=1e18,Mx=-1e18;
		for(int k=i;k<=j;k++)Mn=min(Mn,T[k]),Mx=max(Mx,T[k]);
		for(int k=i;k<=j;k++)w[k].mnt=T[i-1]+e[k].t,w[k].mxt=Mx;
		i=j;
	}
	for(int i=1;i<=n;i++)w[i].p=e[i].p;
	sort(w+1,w+n+1);
//	for(int i=1;i<=n;i++)cout<<w[i].mnt<<" "<<w[i].mxt<<"\n";
//	cout<<check(0.3)<<"\n";
//	return 0;
	double l=0,r=1,ans=0;
	while(l+1e-7<=r)
	{
		double mid=(l+r)/2.0;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	cout<<fixed<<setprecision(6)<<ans<<"\n";
	return 0;
}