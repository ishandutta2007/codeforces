#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,p[MAXN];
bool check(int N){For(i,0,16)if(N==1<<i)return 1;return 0;}
int main()
{
	cin>>N;
	if(N&1)cout<<"NO\n";
	else
	{
		cout<<"YES\n";int M=N;
		while(M){int x=1;while(1<<x<=M)x++;int l=(1<<x)-M-1;For(i,l,M)p[i]=M+l-i;M=l-1;}
		For(i,1,N)cout<<p[i]<<" \n"[i==N];
	}
	if(check(N)||N<=5)cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		if(N==6)cout<<"5 3 2 6 1 4\n";
		else
		{
			cout<<"5 3 2 6 1 7 4 ";int x=8;
			while(x<=N){int l=x,r=min((x<<1)-1,N);For(i,l,r)cout<<(i<r?i+1:l)<<' ';x<<=1;}
		}
		cout<<'\n';
	}
	return 0;	
}