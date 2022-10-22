#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';}int cnt=0;bool flag=1;For(i,1,N)cnt+=1-a[i],flag&=a[i]==a[N-i+1];
		if(flag){cout<<((cnt&1)&&cnt>1?"ALICE\n":"BOB\n");}else cout<<((N&1)&&!a[N+1>>1]&&cnt==2?"DRAW\n":"ALICE\n");
	}
	return 0;
}