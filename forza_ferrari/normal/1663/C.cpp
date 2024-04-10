#include<iostream>
using namespace std;
int n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        ans+=x;
    }
    cout<<ans<<'\n';
    return 0;
}