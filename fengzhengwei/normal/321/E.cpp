#include<bits/stdc++.h>
using namespace std;
const int N=4005;
char gc()
{
	static char buf[1<<16],*S,*T;
	if(T==S)
	{
		T=(S=buf)+fread(buf,1,1<<16,stdin);
		if(T==S) return EOF;
	}
	return *S++;
}
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
int n,m;
int a[N][N],f[N][805];
int calc(int i,int j){return a[i][i]+a[j][j]-2*a[i][j];}
void ztef(int l,int r,int tl,int tr,int id)
{
//	cerr<<l<<" "<<r 
	if(l>r)return;
	int mid=(l+r)>>1,x,t;
	for(int i=tl;i<=tr&&i<=mid+1;i++)
		if((x=f[i-1][id-1]+calc(i-1,mid))<f[mid][id])f[mid][id]=x,t=i;
	ztef(l,mid-1,tl,t,id);
	ztef(mid+1,r,t,tr,id);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read(),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	memset(f,0x3f,sizeof(f));
	for(int i=0;i<=0;i++)f[0][i]=0;
	for(int i=1;i<=m;i++)ztef(1,n,1,n,i);
	printf("%d\n",f[n][m]/2);
	return 0;
}