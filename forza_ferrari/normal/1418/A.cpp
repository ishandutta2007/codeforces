#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,x,y,n;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>n;
        cout<<(n*(y+1)-1+x-2)/(x-1)+n<<'\n';
    }
    return 0;
}