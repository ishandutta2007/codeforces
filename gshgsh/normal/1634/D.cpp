#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001

int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int ask(int x,int y,int z){cout<<"? "<<x<<' '<<y<<' '<<z<<endl;return get();}
int Not(int a,int b,int c){int d=1;while(d==a||d==b||d==c)d++;return d;}
void solve(int a,int b,int c,int d,int&x,int&y)
{
	vector<pair<int,int>>p;p.push_back({ask(a,b,c),d});p.push_back({ask(a,b,d),c});p.push_back({ask(a,c,d),b});p.push_back({ask(b,c,d),a});
	sort(p.begin(),p.end());x=p[0].second;y=p[1].second;
}
int main()
{
	int T=get();
	while(T--)
	{
		int N=get(),x,y;solve(1,2,3,4,x,y);
		For(i,3,N/2)solve(x,y,i*2-1,i*2,x,y);if(N&1)solve(x,y,N,Not(x,y,N),x,y);cout<<"! "<<x<<' '<<y<<endl;
	}
	return 0;
}