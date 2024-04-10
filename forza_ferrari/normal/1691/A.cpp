#include<iostream>
#include<cstdio>
using namespace std;
int t,n,cnt[2];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt[0]=cnt[1]=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            ++cnt[x&1];
        }
        cout<<min(cnt[0],cnt[1])<<'\n';
    }
    return 0;
}