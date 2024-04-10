#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool flag[MN+5];
vector<pair<int,int> >ans;
struct Line{int a,b,c,id;}v[MN+5];
void GetInter(const Line&a,const Line&b,long long&Xa,long long&Xb,long long&Ya,long long&Yb)
{
	Ya=1LL*b.a*a.c-1LL*a.a*b.c;Yb=1LL*a.a*b.b-1LL*b.a*a.b;	
	Xa=1LL*a.c*b.b-1LL*b.c*a.b;Xb=1LL*b.a*a.b-1LL*a.a*b.b;
}
bool Cross(const Line&a,long long Xa,long long Xb,long long Ya,long long Yb){return (a.a*Xa*Yb+a.b*Ya*Xb+a.c*Xb*Yb)==0;}
void Solve(int n,int k)
{
	if(n<=k) 
	{
		puts("YES");printf("%d\n",ans.size()+n);
		for(int j=0;j<ans.size();++j)
			printf("%d %d\n",ans[j].first,ans[j].second);
		for(int j=0;j<n;++j) printf("%d -1\n",v[j].id);
		exit(0);
	}
	if(!k) return; 
	int Lim=(n+k-1)/k;
	for(int tms=1;tms<=40;++tms)
	{
		int num=0,x,y,t=0;long long Xa,Xb,Ya,Yb;
		do x=rand()%n,y=rand()%n,++t; while(t<10&&(x==y||1LL*v[x].a*v[y].b==1LL*v[y].a*v[x].b));	
		if(t>=10) return;
		GetInter(v[x],v[y],Xa,Xb,Ya,Yb);
		for(int j=0;j<n;++j) num+=(flag[j]=Cross(v[j],Xa,Xb,Ya,Yb));
		if(num>=Lim)
		{
			int top=0;ans.push_back(make_pair(v[x].id,v[y].id));
			for(int j=0;j<n;++j) if(!flag[j]) v[top++]=v[j];
			Solve(top,k-1); 
			return;
		}
	}
}

int main()
{
	srand(2333U);
	int n=read(),k=read();
	for(int i=1;i<=n;++i)
	{
		int A=read(),B=read(),C=read();
		v[i-1]=((Line){A,B,C,i});	
	}
	Solve(n,k);
	puts("NO");
	return 0;
}