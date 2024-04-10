#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void lmao(long long b,long long bo[],int *p)
{
    int c=0;
    for(long long i=2;i<=sqrt(b)+1;i++)
    {
        if(b%i==0)
        {
            bo[c*2]=i;
            bo[c*2+1]=0;
            for(;;)
            {
                if(b%i!=0) break;
                bo[c*2+1]++;
                b/=i;
            }
            c++;
        }
    }
    if(b>1)
    {
        bo[c*2]=b;
        bo[c*2+1]=1;
        c++;
        b=1;
    }
    *p=c;
    return;
}

long long xd(long long n,long long i)
{
    long long t=0;
    long long k=n;
    for(long long j=i;j<=k;)
    {
        k/=j;
        t+=k;
    }
    return t;
}

int main()
{
    long long n,b;
    cin>>n>>b;
    int c=0;
    long long bo[10000];
    lmao(b,bo,&c);
    long long ans;
    for(int i=0;i<c;i++)
    {
        long long t=xd(n,bo[2*i]);
        if(i==0)
        {
            ans=t/bo[2*i+1];
        }
        else ans=min(ans,t/bo[2*i+1]);
    }
    cout<<ans;
    return 0;
}