#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<pair<int,int>,int>mp;
int n,q[MN+5],Ans[MN+5],top,flag[MN+5];
struct hito{double a,b;int id;}s[MN+5];
bool cmp(const hito&x,const hito&y){return x.a==y.a?x.b<y.b:x.a<y.a;}
inline double Calc(int x,int y){return (s[x].b-s[y].b)/(s[x].a-s[y].a);}
int main()
{
	n=read();int num=0;
	for(int i=1;i<=n;++i) 
	{
		int x=read(),y=read();	
		if(mp[make_pair(x,y)]) flag[i]=mp[make_pair(x,y)];
		else mp[make_pair(x,y)]=i,s[++num]=(hito){1./x,1./y,i};
	}
	sort(s+1,s+num+1,cmp);double mn=1e9;
	for(int i=1;i<=num;++i) if(s[i].b<mn) 
	{
		while(top>1&&Calc(q[top],q[top-1])>Calc(i,q[top])) --top;
		q[++top]=i;mn=s[i].b;
	}
	for(int i=1;i<=top;++i) Ans[s[q[i]].id]=1;
        for(int i=1;i<=n;++i) if(flag[i]?Ans[flag[i]]:Ans[i]) printf("%d ",i);
	return 0;
}