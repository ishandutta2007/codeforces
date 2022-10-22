#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5001
int N,M,a[MAXN];
bool check(int x){For(i,x,N){if(a[i]>a[i-x+1])return 1;if(a[i]<a[i-x+1])return 0;}return 1;}
int main()
{
	cin>>N>>M;For(i,1,N){char c;cin>>c;a[i]=c-'a';}int x=N;For(i,2,N)if(check(i)){x=i-1;break;}
	For(i,1,M)cout<<char(a[(i-1)%x+1]+'a');cout<<endl;return 0;
}