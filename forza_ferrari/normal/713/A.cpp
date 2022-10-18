#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define int long long
int n;
map<int,int> mp;
signed main()
{
    cin>>n;
    while(n--)
    {
        char opt;
        int x;
        cin>>opt>>x;
        if(opt=='?')
        {
            cout<<mp[x]<<endl;
            continue;
        }
        int tag=opt=='+'? 1:-1,val=0,tmp=1;
        for(register int i=0;i<=18;++i)
        {
            val+=((x/tmp)&1)*tmp;
            tmp*=10;
        }
        mp[val]+=tag;
    }
    return 0;
}