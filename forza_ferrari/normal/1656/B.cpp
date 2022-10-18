#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int t,n,m,a[200001];
map<int,bool> mp;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        mp.clear();
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            mp[a[i]]=1;
        }
        bool flag=0;
        for(int i=1;i<=n;++i)
            if(mp[a[i]-m])
            {
                flag=1;
                break;
            }
        puts(flag? "YES":"NO");
    }
    return 0;
}