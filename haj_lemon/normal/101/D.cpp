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
struct Info{int nu,ne,qu;}a[N*2];
int b[N],num,n,x,y,z,nh;
struct Onfo{ll an,su,si;}dp[N],h[N];
void jb(int x,int y,int z){a[++num].nu=y;a[num].ne=b[x];b[x]=num;a[num].qu=z;}
bool comp(const Onfo &a,const Onfo &b){return a.su*b.si<a.si*b.su;}
void dfs(int x,int fa){
	for (int y=b[x];y;y=a[y].ne)
		if (a[y].nu!=fa) dfs(a[y].nu,x);
	nh=0;
	dp[x].si=1;dp[x].an=0;dp[x].su=0;
	for (int y=b[x];y;y=a[y].ne){
		if (a[y].nu!=fa){
			h[++nh]=dp[a[y].nu];
			h[nh].su+=a[y].qu*2;
			h[nh].an+=a[y].qu*h[nh].si;
		}
	}
	sort(h+1,h+nh+1,comp);
	for (int i=1;i<=nh;i++){dp[x].si+=h[i].si;dp[x].an+=h[i].an+dp[x].su*h[i].si;dp[x].su+=h[i].su;}
}
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	read(n);
	for (int i=1;i<n;i++){read(x);read(y);read(z);jb(x,y,z);jb(y,x,z);}
	dfs(1,0);
	printf("%.10Lf",((long double)dp[1].an)/(n-1));
	return 0;
}