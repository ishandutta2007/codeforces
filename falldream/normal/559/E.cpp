#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 300
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long f[MN+5][MN+5],ans=0;vector<int> v[MN+5],V[MN+5];
int L[MN+5],n,num=0,a[MN+5],len[MN+5],R[MN+5],mx[MN+5][MN+5],lt[MN+5],rt[MN+5],pos[MN+5];
inline int get(int x){return lower_bound(L+1,L+num+1,x)-L;}
inline void Re(long long&x,long long y){y>x?x=y:0;} 

int Solve(int x,int r,int p)
{
//	cout<<"Solve"<<x<<" "<<r<<" "<<p<<endl;
	for(;x<r;++x)
		for(int j=0;j<V[x].size();++j)
			if(V[x][j]!=p)
				r=max(r,rt[V[x][j]]);//cout<<V[x][j]<<" "<<rt[V[x][j]]<<endl;
	return r;
}

int main()
{
	n=read();
	for(int i=1;i<=n;++i) L[++num]=a[i]=read(),len[i]=read(),L[++num]=a[i]-len[i],L[++num]=a[i]+len[i];
	sort(L+1,L+num+1);num=unique(L+1,L+num+1)-L-1;
	memset(f,200,sizeof(f));f[1][0]=0;
	for(int i=1;i<=n;++i) 
	{
		pos[i]=get(a[i]),lt[i]=get(a[i]-len[i]),rt[i]=get(a[i]+len[i]);
		R[pos[i]]=max(R[pos[i]],rt[i]);for(int j=lt[i];j<pos[i];++j) v[j].push_back(i);
		V[pos[i]].push_back(i);
	}
	for(int i=1;i<=num;++i)
	{
		long long mx=-1e9,from,mx2=-1e9;
		for(int j=0;j<=n;++j) 
			if(f[i][j]>mx) mx2=mx,mx=f[i][j],from=j;
			else if(f[i][j]>mx2) mx2=f[i][j];
		Re(f[i+1][0],mx);
		for(int j=0;j<V[i].size();++j)
		{
			int w=from==V[i][j]?mx2:mx;
			int p=Solve(i+1,rt[V[i][j]],0);
		//	cout<<"Go"<<i<<" "<<V[i][j]<<" "<<p<<endl;
			Re(f[p][0],w+L[p]-L[i]);	
		}
		for(int j=0;j<v[i].size();++j)
		{
			int p=Solve(i+1,pos[v[i][j]],v[i][j]);	
			Re(f[p][v[i][j]],mx+L[p]-L[i]);
		//	cout<<"go"<<i<<" "<<v[i][j]<<" "<<p<<endl;
		}
		Re(ans,mx); 
	}
	cout<<ans;
	return 0;
}