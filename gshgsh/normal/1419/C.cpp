#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int T,N,M,a[MAXN];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N>>M;bool flag=0;For(i,1,N)cin>>a[i],flag|=a[i]!=M;if(!flag){cout<<0<<endl;continue;}
        flag=0;For(i,1,N)flag|=a[i]==M;int sum=0;For(i,1,N)sum+=a[i];cout<<(sum==N*M||flag?1:2)<<endl;
    }
    return 0;
}