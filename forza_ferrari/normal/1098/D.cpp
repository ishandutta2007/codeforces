#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int n;
multiset<int> s[31];
long long sum[31];
int main()
{
    cin>>n;
    while(n--)
    {
        char opt;
        int x,pos=0;
        cin>>opt>>x;
        for(;1<<pos<=x;++pos);
        --pos;
        if(opt=='+')
        {
            sum[pos]+=x;
            s[pos].insert(x);
        }
        if(opt=='-')
        {
            sum[pos]-=x;
            s[pos].erase(s[pos].find(x));
        }
        long long res=0,ans=0;
        for(int i=0;i<30;++i)
        {
            ans+=s[i].size();
            if(!s[i].empty()&&*s[i].begin()>2ll*res)
                --ans;
            res+=sum[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}