#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 201
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';}
		if(a[N-3]==2&&a[N-2]==0&&a[N-1]==2&&a[N]==0){cout<<"YES\n";continue;}
		if(a[1]==2&&a[N-2]==0&&a[N-1]==2&&a[N]==0){cout<<"YES\n";continue;}
		if(a[1]==2&&a[2]==0&&a[N-1]==2&&a[N]==0){cout<<"YES\n";continue;}
		if(a[1]==2&&a[2]==0&&a[3]==2&&a[N]==0){cout<<"YES\n";continue;}
		if(a[1]==2&&a[2]==0&&a[3]==2&&a[4]==0){cout<<"YES\n";continue;}cout<<"NO\n";
	}
	return 0;
}