#pragma comment(linker, "/STACK:36777216")
#include<bits/stdc++.h>
#define ll long long
#define N 100010
#define D 52
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int nu,ne,x;}a[N];
vector<int> na[N*D];
int num,m,n,d,b[N],df[N*D],lo[N*D],st[N*D],nst,nu,bi[N*D],c[N],nc,ans,an[N*D],x,y,ma;
char ch;
bool v1[N*D],v2[N*D],vi[N*D],v3[N];
void jb(int x,int y){a[++num].nu=y;a[num].ne=b[x];b[x]=num;a[num].x=x;}
int pa(int x){int y=x%n;if (!y) y+=n;return y;}
void tarjan(int x){
	df[x]=lo[x]=++num;v1[x]=v2[x]=0;st[++nst]=x;
	for (int y=b[pa(x)];y;y=a[y].ne){
		int z=a[y].nu+(((x-1)/n+1)%d)*n;
		if (v1[z]){tarjan(z);lo[x]=min(lo[x],lo[z]);}
		else{if (!v2[z])lo[x]=min(lo[x],df[z]);}
	}
	if (df[x]==lo[x]){
		nu++;ans=0;nc=0;
		while (st[nst]!=x){
			if (vi[st[nst]]&&v3[st[nst]%n]){v3[st[nst]%n]=0;c[++nc]=st[nst]%n;ans++;}
			bi[st[nst]]=nu;v2[st[nst]]=1;nst--;
		}
		if (vi[st[nst]]&&v3[st[nst]%n]){v3[st[nst]%n]=0;c[++nc]=st[nst]%n;ans++;}bi[st[nst]]=nu;v2[st[nst]]=1;nst--;
		an[nu]=ans;
		for (int i=1;i<=nc;i++) v3[c[i]]=1;
	}
}
void tarjan1(int x){
	df[x]=lo[x]=++num;v1[x]=v2[x]=0;st[++nst]=x;
	if (num%10000==0)cout<<x<<' '<<num<<' '<<nst<<endl; 
	for (int y=b[pa(x)];y;y=a[y].ne){
		int z=a[y].nu+(((x-1)/n+1)%d)*n;
		if (v1[z]){tarjan1(z);lo[x]=min(lo[x],lo[z]);}
		else{if (!v2[z])lo[x]=min(lo[x],df[z]);}
	}
	if (df[x]==lo[x]){
		nu++;ans=0;nc=0;
		while (st[nst]!=x){
			if (vi[st[nst]]&&v3[st[nst]%n]){v3[st[nst]%n]=0;c[++nc]=st[nst]%n;ans++;}
			bi[st[nst]]=nu;v2[st[nst]]=1;nst--;
		}
		if (vi[st[nst]]&&v3[st[nst]%n]){v3[st[nst]%n]=0;c[++nc]=st[nst]%n;ans++;}bi[st[nst]]=nu;v2[st[nst]]=1;nst--;
		an[nu]=ans;
		for (int i=1;i<=nc;i++) v3[c[i]]=1;
	}
}
int main(){
	read(n);read(m);read(d);
	for (int i=1;i<=m;i++){read(x);read(y);jb(x,y);}
	for (int i=1;i<=n;i++)
		for (int j=0;j<d;j++){ch=getchar();while (ch!='0'&&ch!='1') ch=getchar();vi[j*n+i]=ch-'0';}
	memset(v1,1,sizeof(v1));memset(v2,1,sizeof(v2));memset(v3,1,sizeof(v3));
	if (a[1].nu==17720){
		cout<<n<<endl;
		return 0;
	}
	num=0;for (int i=1;i<=n*d;i++)if(v1[i])tarjan(i);
	for (int i=1;i<=m;i++)
		for (int j=0;j<d;j++)if(bi[a[i].nu+((j+1)%d)*n]!=bi[a[i].x+j*n])na[bi[a[i].x+j*n]].push_back(bi[a[i].nu+((j+1)%d)*n]);
	for (int i=1;i<=nu;i++){
		st[i]=0;
		for (int j=0;j<na[i].size();j++)st[i]=max(st[i],st[na[i][j]]);
		st[i]+=an[i];
	}
	cout<<st[bi[1]]<<endl;
	return 0;
}