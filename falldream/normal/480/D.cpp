#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 500
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN*2+5];
int n,S,f[MN+5][MN*2+5],F[MN+5][MN*2+5],q[MN+5],top,ans=0;
struct data{int l,r,w,s,v;}s[MN+5];
bool cmp(const data&a,const data&b){return a.l==b.l?a.r<b.r:a.l>b.l;}
inline void R(int&x,int y){y>x?x=y:0;} 
int main()
{
	n=read();S=read();
	for(int i=1;i<=n;++i) s[i].l=read(),s[i].r=read(),s[i].w=read(),s[i].s=read(),s[i].v=read();
	s[++n]=(data){0,2*n,0,S,0};sort(s+1,s+n+1,cmp);memset(F,200,sizeof(F));
	for(int i=1;i<=n;++i)
	{
	//	cout<<"no."<<i<<" "<<s[i].l<<" "<<s[i].r<<endl;
		q[top=1]=s[i].r;q[++top]=s[i].l;
		for(int j=1;j<i;++j) if(s[j].r<=s[i].r) q[++top]=s[j].r;
		sort(q+1,q+top+1);top=unique(q+1,q+top+1)-q-1; 
		for(int j=1;j<=top;++j) memset(f[j],200,sizeof(f[j]));
		for(int j=top;j;--j)
		{
			for(int w=0;w<=min(s[i].s,S-s[i].w);++w) R(f[j][w],j==top?0:f[j+1][w]),R(f[j][w],w?f[j][w-1]:0);
			for(int k=0;k<v[q[j]].size();++k)
			{
				int x=v[q[j]][k],pos=upper_bound(q+1,q+top+1,s[x].l)-q-1;
		//		cout<<i<<" "<<j<<" "<<q[j]<<" "<<v[q[j]][k]<<" "<<pos<<endl;	
				for(int w=0;w<=min(s[i].s,S-s[i].w);++w) 
					R(f[pos][w],f[j][w]+F[x][w]);//cout<<f[pos][w]<<endl;
			}
		}
	//	for(int j=0;j<=min(s[i].s,S-s[i].w);++j) printf("%d %d %d\n",i,j+s[i].w,f[1][j]+s[i].v);
		for(int j=0;j<=min(s[i].s,S-s[i].w);++j) ans=max(ans,F[i][j+s[i].w]=f[1][j]+s[i].v);
		for(int j=min(s[i].s,S-s[i].w)+1;j<=S;++j) R(F[i][j],F[i][j-1]);
		v[s[i].r].push_back(i); 
	}
	printf("%d\n",ans);
	return 0;
}