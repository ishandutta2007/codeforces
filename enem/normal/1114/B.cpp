#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int a[n],a0[n];
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        a[i]=k;
        a0[i]=k;
    }
    sort(a,a+n);
    long long sum=0;
    int re=a[n-k*m];
    int lb=0;
    for(int i=0;i<k*m;i++)
    {
        sum+=a[n-1-i];
        if(a[n-1-i]==re) lb++;
    }
    cout<<sum<<'\n';
    int m0=m;
    for(int i=0;i<n;i++)
    {
        if(a0[i]>re) m0--;
        else if(a0[i]==re&&lb>0)
        {
            m0--;
            lb--;
        }
        if(m0==0)
        {
            m0=m;
            cout<<i+1<<' ';
            k--;
            if(k==1) break;
        }
    }
    return 0;
}