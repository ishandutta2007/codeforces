#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);
		int cnt=0;For(i,1,N)cnt+=a[i]<=0;if(cnt==N){cout<<N<<endl;continue;}
		bool flag=1;For(i,2,cnt)if(a[i]-a[i-1]<a[cnt+1]){flag=0;break;}cout<<cnt+flag<<endl;
	}
	return 0;
}