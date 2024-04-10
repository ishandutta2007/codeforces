#include<iostream>
#include<cstdio>
using namespace std;
int t,cnt;
int main()
{
    cin>>t;
    while(t--)
    {
        cnt=0;
        for(int i=1;i<=4;++i)
        {
            int x;
            cin>>x;
            cnt+=x;
        }
        cout<<(cnt==0? 0:cnt==4? 2:1)<<'\n';
    }
    return 0;
}