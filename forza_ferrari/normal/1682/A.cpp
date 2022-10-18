#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        s=" "+s;
        int ans=0;
        for(int i=((n+1)>>1);i>=1;--i)
            if(s[i]!=s[(n+1)>>1])
                break;
            else
                ++ans;
        cout<<(ans<<1)-(n&1)<<'\n';
    }
    return 0;
}