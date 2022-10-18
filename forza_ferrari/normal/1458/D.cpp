#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,cnt[1000001][2];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        s=" "+s;
        int sum=n;
        for(int i=1;i<=n;++i)
        {
            ++cnt[sum][s[i]-'0'];
            sum+=s[i]=='0'? -1:1;
        }
        sum=n;
        for(int i=1;i<=n;++i)
        {
            if((cnt[sum][0]&&cnt[sum-1][1])||!cnt[sum][1])
            {
                cout<<0;
                --cnt[sum][0];
                --sum;
            }
            else
            {
                cout<<1;
                --cnt[sum][1];
                ++sum;
            }
        }
        cout<<'\n';
    }
    return 0;
}