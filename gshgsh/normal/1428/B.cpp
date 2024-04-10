#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int T,N,a[MAXN],cnt;
int main()
{
	cin>>T;
	while(T--)
	{
		char c;cin>>N;cnt=0;For(i,0,N-1)cin>>c,a[i]=c=='>'?1:c=='<'?-1:0;
		bool flag1=0,flag2=0;For(i,0,N-1){if(a[i]==-1)flag1=1;if(a[i]==1)flag2=1;if(a[(N+i-1)%N]==0||a[i]==0)cnt++;}
		cout<<(flag1&&flag2?cnt:N)<<endl;
	}
	return 0;
}