#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef long long ll;

inline void print(int x,int y){ printf("%d %d",x,y); exit(0);}

int main(void)
{
	ll n,m,d;
	cin>>n>>m>>d;
	
	if(d<n) print(d+1,1);
	d-=n;
	int x = n-d/(m-1);
	if(x&1) print(x, m-d%(m-1));
	else print(x, d%(m-1)+2);
	return 0;
}