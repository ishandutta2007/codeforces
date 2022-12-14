#include<bits/stdc++.h>
#define MN 1000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v;
vector<pair<int,int> >ans,ans2;
int n,b[MN+5][MN+5],B[MN+5][MN+5]; 
void Solve1(vector<int> v)
{
	if(v.size()<=3) return;
	int beg=v[0];
	for(int i=2;i+1<v.size();++i)
		if(b[beg][v[i]])
		{
			vector<int> p1(v.begin(),v.begin()+i+1);
			Solve1(p1);
			vector<int> p2(v.begin()+i,v.end());
			p2.insert(p2.begin(),beg);
			Solve1(p2);
			return;
		}
	int it=-1,d;
	for(int i=2;i+1<v.size();++i)
		if(b[v[1]][v[i]]&&b[v.back()][v[i]]) it=i;
	d=v[it]; 
	ans.push_back(make_pair(v[1],v.back()));
	b[v[1]][v.back()]=b[v.back()][v[1]]=0;
	b[beg][d]=b[d][beg]=1;
	vector<int> p1(v.begin(),v.begin()+it+1);
	vector<int> p2(v.begin()+it,v.end());
	p2.insert(p2.begin(),beg);
	Solve1(p1);Solve1(p2);
}
void Solve2(vector<int> v)
{
	if(v.size()<=3) return;
	int beg=v[0];
	for(int i=2;i+1<v.size();++i)
		if(B[beg][v[i]])
		{
			vector<int> p1(v.begin(),v.begin()+i+1);
			Solve2(p1);
			vector<int> p2(v.begin()+i,v.end());
			p2.insert(p2.begin(),beg);
			Solve2(p2);
			return;
		}
	int it=-1,d;
	for(int i=2;i+1<v.size();++i)
		if(B[v[1]][v[i]]&&B[v.back()][v[i]]) it=i;
	d=v[it]; 
	ans2.push_back(make_pair(beg,d));
	B[v[1]][v.back()]=B[v.back()][v[1]]=0;
	B[beg][d]=B[d][beg]=1;
	vector<int> p1(v.begin(),v.begin()+it+1);
	vector<int> p2(v.begin()+it,v.end());
	p2.insert(p2.begin(),beg);
	Solve2(p1);Solve2(p2);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) v.push_back(i),b[i][i%n+1]=b[i%n+1][i]=B[i][i%n+1]=B[i%n+1][i]=1;
	for(int i=1,j,k;i<=n-3;++i) j=read(),k=read(),b[j][k]=b[k][j]=1;
	for(int i=1,j,k;i<=n-3;++i) j=read(),k=read(),B[j][k]=B[k][j]=1;
	Solve1(v);Solve2(v);
	printf("%d\n",ans.size()+ans2.size());
	for(int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].first,ans[i].second);
	for(int i=ans2.size();i--;) printf("%d %d\n",ans2[i].first,ans2[i].second);
	return 0;
}