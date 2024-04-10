#include<iostream>
#include<cstdio>
using namespace std;
int n,a[51],minn,cnt;
int main()
{
    cin>>n;
    minn=100;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]==minn)
            ++cnt;
        if(a[i]<minn)
        {
            minn=a[i];
            cnt=1;
        }
    }
    puts(cnt<=(n>>1)? "Alice":"Bob");
    return 0;
}