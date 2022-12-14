#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 50000
#define N 65536
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

pair<int,int> T[12][N*2+5];
int l[MN+5],r[MN+5],n,k,a[12][MN+5],rk[12][MN+5],s[MN+5],size[MN+5],p[12][MN+5],now;
bool cmp(int x,int y){return a[now][x]>a[now][y];}
inline int getfa(int*s,int x){return s[x]?s[x]=getfa(s,s[x]):x;}

void Add(int x,int y)
{
	if(x<y) return;swap(x,y);
	for(;getfa(s,x)!=getfa(s,y);)
	{
	//	cout<<x<<" "<<y<<endl;
		int L=l[getfa(s,y)];
		int R=getfa(s,L-1);
		r[R]=r[getfa(s,y)];size[R]+=size[getfa(s,y)];s[getfa(s,y)]=R;
		y=L-1;
	}
}
pair<int,int> Up(pair<int,int> x,pair<int,int> y){return make_pair(max(x.first,y.first),min(x.second,y.second));} 
void Renew(pair<int,int>*T,int x,pair<int,int> v){for(T[x+=N]=v;x>>=1;) T[x]=Up(T[x<<1],T[x<<1|1]);}
pair<int,int> Query(pair<int,int>*T,int l,int r)
{
	pair<int,int> res(0,1e9);
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) res=Up(res,T[l+1]);
		if( r&1) res=Up(res,T[r-1]);
	}
	return res;
}

int main()
{
	n=read();k=read();
	for(int i=1;i<=k;++i)for(int j=1;j<=n;++j)rk[i][j]=j;
	for(int i=1;i<=n;l[i]=r[i]=i,++i) for(int j=1;j<=k;++j) a[j][i]=read();
	for(int i=1;i<=k;++i)for(int j=1;j<=N*2+1;++j) T[i][j]=make_pair(0,1e9); 
	for(int j=1;j<=k;++j)
	{
		now=j;
		sort(rk[j]+1,rk[j]+n+1,cmp);
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=k;++j) p[j][rk[j][i]]=i;
	for(int i=1,mx=1e9;i<=n;++i)
	{
		mx=min(mx,p[1][i]);
		for(int j=2;j<=k;++j) 
		{
			int r=Query(T[j],p[j][i],n).second;
			if(r>0&&r<=n) Add(p[1][i],r);
			int l=Query(T[j],1,p[j][i]).first;
			if(l>0&&l<=n) Add(l,p[1][i]);
			Renew(T[j],p[j][i],make_pair(p[1][i],p[1][i]));
		}
		++size[getfa(s,p[1][i])];
		printf("%d\n",size[getfa(s,mx)]);
	}
	return 0;
}