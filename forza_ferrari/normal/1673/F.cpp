#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int n,m,num[32];
map<int,int> mp;
int main()
{
    cin>>n>>m;
    for(int i=0;i<32;++i)
        mp[num[i]=i^(i>>1)]=i;
    for(int i=1;i<=n;++i,cout<<endl)
        for(int j=1;j<n;++j)
        {
            int w=num[j]^num[j-1],val=0;
            for(int k=0;k<5;++k)
                val|=(w>>k&1)<<(k<<1);
            cout<<val<<'\n';
        }
    for(int i=1;i<n;++i,cout<<endl)
        for(int j=1;j<=n;++j)
        {
            int w=num[i]^num[i-1],val=0;
            for(int k=0;k<5;++k)
                val|=(w>>k&1)<<(k<<1|1);
            cout<<val<<'\n';
        }
    int lst=0;
    while(m--)
    {
        int w;
        cin>>w;
        w^=lst;
        int x=0,y=0;
        for(int i=0;i<10;++i)
            if(i&1)
                x|=(w>>i&1)<<(i>>1);
            else
                y|=(w>>i&1)<<(i>>1);
        cout<<mp[x]+1<<" "<<mp[y]+1<<endl;
        lst=w;
    }
    return 0;
}