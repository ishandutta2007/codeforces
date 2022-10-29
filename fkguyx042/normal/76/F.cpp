#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
int n,V,w,x[N],y[N],p[N],a[N]; bool b[N];
bool cmpx(const int i,const int j){return x[i]==x[j]?y[i]<y[j]:x[i]<x[j];}
bool cmpy(const int i,const int j){return y[i]==y[j]?x[i]<x[j]:y[i]<y[j];}
int get(int x){int res=0; for (;x;x-=x&-x) res=res>a[x]?res:a[x]; return res;}
void modify(int x,int v){for (;x<=n;x+=x&-x) a[x]=a[x]>v?a[x]:v;}
int work(bool flag)
{
	for (int k=0;k<n;k++){int i=p[k],f=get(y[i])+1; if (flag+b[i]+f==1) f=0; modify(y[i],f);}
	int f=get(n); memset(a,0,sizeof(a)); return f;
}
int main()
{
	scanf("%d",&n); for (int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]),p[i]=i; scanf("%d",&V);
	for (int i=0;i<n;i++) w=x[i],x[i]=y[i]*V-w,y[i]=y[i]*V+w,b[i]=x[i]>=0 && y[i]>=0;
	std::sort(p,p+n,cmpy); for (int i=0;i<n;i++) y[p[i]]=i+1; std::sort(p,p+n,cmpx);
	printf("%d %d\n",work(0),work(1)); return 0;
}