#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector> 
#define MN 400
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
double P[MN+5][MN+5],ans=0,mx[MN+5][MN+5],Mx[MN+5],MMx[MN+5];vector<int> v[MN+5];
int n,m,d[MN+5][MN+5],head[MN+5],cnt=0,du[MN+5];
struct edge{int to,next;}e[MN*MN+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}
int main()
{
	n=read();m=read();
	memset(d,63,sizeof(d));
	for(int i=1;i<=n;++i) d[i][i]=0;
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);++du[x];++du[y];d[x][y]=d[y][x]=1;
	}
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
		if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
	for(int i=1;i<=n;++i)
	{
		double res=0;
		for(int j=0;j<n;++j) v[j].clear(),MMx[j]=0;
		for(int j=1;j<=n;++j) v[d[i][j]].push_back(j);
		for(int j=0;j<n;++j)for(int k=1;k<=n;++k) P[j][k]=0;
		for(int D=0;D<n;++D) if(v[D].size())
		{
			for(int j=0;j<v[D].size();++j)
			{
				int t=v[D][j];
				for(int l=head[t];l;l=e[l].next)
					P[D][e[l].to]+=1./n/du[t];
				//	cout<<i<<" dep= "<<D<<" "<<t<<" -> "<<e[l].to<<" += "<<1./n/du[t]<<endl;
			}
		}
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
				for(int ad=-1;ad<=1;++ad)
					if(d[i][k]+ad>=0) 
					{
					//	cout<<i<<" used "<<j<<" pos = "<<k<<" ad= "<<ad<<" "<<d[i][k]+ad<<" "<<P[d[i][k]+ad][k]<<endl;
						 Mx[d[i][k]+ad]-=mx[d[i][k]+ad][d[j][k]];
						 mx[d[i][k]+ad][d[j][k]]=max(P[d[i][k]+ad][k],mx[d[i][k]+ad][d[j][k]]);
						 Mx[d[i][k]+ad]+=mx[d[i][k]+ad][d[j][k]];
					//	 cout<<"after Mx["<<d[i][k]+ad<<"] = "<<Mx[d[i][k]+ad]<<endl;
					}
			for(int k=0;k<n;++k) MMx[k]=max(MMx[k],Mx[k]),Mx[k]=0;
			for(int k=1;k<=n;++k)
				for(int ad=-1;ad<=1;++ad)
					if(d[i][k]+ad>=0) mx[d[i][k]+ad][d[j][k]]=0;
		}
		for(int j=0;j<n;++j) if(v[j].size()) res+=max(1./n,MMx[j]);
		ans=max(ans,res);
	}
	printf("%.10lf",ans);
	return 0;
}