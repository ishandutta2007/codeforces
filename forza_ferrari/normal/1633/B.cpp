#include<iostream>
#include<cstdio>
using namespace std;
int t,cnt[2];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        cnt[0]=cnt[1]=0;
        for(auto i:s)
            ++cnt[i-'0'];
        if(cnt[0]==cnt[1])
            cout<<max(0,cnt[0]-1)<<'\n';
        else
            cout<<min(cnt[0],cnt[1])<<'\n';
    }
    return 0;
}