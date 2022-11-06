#include<bits/stdc++.h>
#define N 1000010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
struct Info{int nu,ne;}a[N*2];
struct Onfo{int nu,we;}an[N];
bool operator >(Onfo x,Onfo y){return x.nu>y.nu||(x.nu==y.nu&&x.we<y.we);}
int b[N],num,m,n,x,y,s[N],f[N],so[N],bi[N],dp[N];
void jb(int x,int y){a[++num].nu=y;a[num].ne=b[x];b[x]=num;}
void dfs(int x,int fa){
	s[x]=1;f[x]=fa;
	for (int y=b[x];y;y=a[y].ne){
		if (a[y].nu!=fa){
			dfs(a[y].nu,x);
			if (s[a[y].nu]>s[so[x]])so[x]=a[y].nu;
			s[x]=max(s[x],s[a[y].nu]+1);
		}
	}
}
void dfs1(int x){
	bi[x]=++num;
	dp[bi[x]]++;
	an[x]=(Onfo){1,0};
	if (so[x]!=0){
		dfs1(so[x]);
		if (an[so[x]].nu>an[x].nu){an[x]=an[so[x]];an[x].we++;}
	}
	for (int y=b[x];y;y=a[y].ne)
		if (a[y].nu!=f[x]&&a[y].nu!=so[x]){
			dfs1(a[y].nu);
			for (int j=1;j<=s[a[y].nu];j++){
				dp[bi[x]+j]+=dp[bi[a[y].nu]+j-1];
				if (dp[bi[x]+j]>an[x].nu||(dp[bi[x]+j]==an[x].nu&&j<an[x].we))an[x]=(Onfo){dp[bi[x]+j],j};
			}
		}
}
int main(){
	read(n);
	for (int i=1;i<n;i++){read(x);read(y);jb(x,y);jb(y,x);}
	dfs(1,0);num=0;dfs1(1);
	for (int i=1;i<=n;i++)printf("%d\n",an[i].we);
	return 0;
}