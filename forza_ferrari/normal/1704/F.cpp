#include<iostream>
#include<cstdio>
#include<bitset>
#include<string>
using namespace std;
int sg[500001],t,n;
bool vis[101];
string s;
int main()
{
    sg[2]=1;
    for(int i=3;i<=1000;++i)
    {
        for(int j=0;j<=100;++j)
            vis[j]=0;
        for(int j=1;j<i;++j)
            vis[sg[j-1]^sg[i-j-1]]=1;
        for(int j=0;j<=100;++j)
            if(!vis[j])
            {
                sg[i]=j;
                break;
            }
        if(sg[i]>=100)
            sg[i]=0;
    }
    for(int i=1001;i<=500000;++i)
        sg[i]=sg[i-68];
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        s=" "+s;
        int cnt=0;
        for(int i=1;i<=n;++i)
            if(s[i]=='R')
                ++cnt;
            else
                --cnt;
        if(cnt)
            cout<<(cnt>0? "Alice":"Bob")<<'\n';
        else
        {
            int lst=1,ans=0;
            for(int i=2;i<=n;++i)
                if(s[i]==s[i-1])
                {
                    ans^=sg[i-lst];
                    lst=i;
                }
            ans^=sg[n-lst+1];
            cout<<(ans? "Alice":"Bob")<<'\n';
        }
    }
    return 0;
}