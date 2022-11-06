#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{ll nu,we,sh;}a[N];
ll n,no=1,ans,x,y,z,m,b[N];
bool comp(const Info &a,const Info &b){if (a.nu==b.nu) return a.we<b.we;return a.nu<b.nu;}
bool comp2(const Info &a,const Info &b){return a.we<b.we;}
int main(){
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i].sh);
	for (int i=1;i<=n;i++){read(a[i].nu);a[i].we=i;}
	sort(a+1,a+n+1,comp);for (int i=1;i<=n;i++) b[i]=a[i].we;
	sort(a+1,a+n+1,comp2);
	while (m--){
		read(x);read(y);ans=0;
		z=min(y,a[x].sh);
		ans=ans+z*a[x].nu;y-=z;a[x].sh-=z;
		while (y&&no<=n){
			z=min(y,a[b[no]].sh);
			ans=ans+z*a[b[no]].nu;y-=z;a[b[no]].sh-=z;
			if (a[b[no]].sh==0) no++;
		}
		if (y>0)puts("0");
		else printf("%I64d\n",ans);
	}
	return 0;
}