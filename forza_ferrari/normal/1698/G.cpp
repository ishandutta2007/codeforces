#include<iostream>
#include<cstdio>//
#include<map>
#include<string>
using namespace std;
string s;
long long n,w,cnt;
map<long long,long long> mp;
inline long long calc(long long a,long long b)
{
    __int128 res=0;
    for(long long i=0;i<n;++i)
        res^=((__int128)(((a>>i)&1)*b))<<i;
    for(long long i=n+n-2;i>=n;--i)
        res^=((__int128)(((res>>i)&1)*w))<<(i-n);
    return (long long)res;
}
inline long long BSGS()
{
    long long k=1,val=1;
    for(int i=0;i<1<<17;++i)
    {
        mp[k]=i;
        k=calc(k,2);
    }
    for(long long i=1;i<=1<<18;++i)
    {
        val=calc(val,k);
        if(mp.count(val))
            return (i<<17)-mp[val];
    }
    return -1;
}
signed main()
{
    cin>>s;
    n=s.length();
    for(long long i=0;i<n;++i)
        w|=(s[i]-48ll)<<i;
    if(!w)
    {
        cout<<"-1\n";
        return 0;
    }
    cnt=1;
    while(w&1^1)
    {
        w>>=1;
        ++cnt;
    }
    n=63-__builtin_clzll(w);
    cout<<cnt<<" "<<cnt+BSGS()<<'\n';
    return 0;
}