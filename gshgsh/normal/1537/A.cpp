#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 51
int T,N,a[MAXN];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N;int sum=0;For(i,1,N)cin>>a[i],sum+=a[i];
        if(sum==N){cout<<"0\n";continue;}if(sum<N){cout<<"1\n";continue;}cout<<sum-N<<endl;
    }
    return 0;
}