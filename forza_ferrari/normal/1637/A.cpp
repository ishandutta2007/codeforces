#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[10001],maxn[10001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        maxn[0]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            maxn[i]=max(maxn[i-1],a[i]);
        }
        int qwq=1e9+7;
        bool flag=0;
        for(int i=n;i>1;--i)
        {
            qwq=min(qwq,a[i]);
            if(qwq<maxn[i-1])
            {
                flag=1;
                break;
            }
        }
        puts(flag? "YES":"NO");
    }
    return 0;
}