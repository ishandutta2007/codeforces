#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int lmao(int n,int s)
{
    int ans=0;
    for(int i=1;i<=10;i++)
    {
        if(n%i==0)
        {
            int temp=max((n/i-s)*(i-1),(i-s)*(n/i-1));
            ans=max(temp,ans);
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int sum=0;
    int xd=0;
    int mina=100;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        a[i]=t;
        sum+=t;
        mina=min(t,mina);
    }
    for(int i=0;i<n;i++)
    {
        int temp=lmao(a[i],mina);
        xd=max(xd,temp);
    }
    cout<<sum-xd;

    return 0;
}