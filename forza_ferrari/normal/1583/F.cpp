#include<iostream>
#include<cstdio>
using namespace std;
int n,k,ans;
int main()
{
    cin>>n>>k;
    ans=1;
    int tmp=k;
    while(tmp<n)
    {
        ++ans;
        tmp*=k;
    }
    cout<<ans<<endl;
    for(register int i=1;i<n;++i)
        for(register int j=i+1;j<=n;++j)
        {
            int tmp=k,col=1;
            while((i-1)/tmp!=(j-1)/tmp)
            {
                tmp*=k;
                ++col;
            }
            cout<<col<<" ";
        }
    cout<<endl;
    return 0;
}