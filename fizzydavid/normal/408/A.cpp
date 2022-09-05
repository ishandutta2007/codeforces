#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
int n,a[111],m[111][111],ans=1<<30; 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int mn=0;
        for(int j=1;j<=a[i];j++)
        {
            cin>>m[i][j];
            mn+=m[i][j]*5+15;
        }
        ans=min(mn,ans);
    }
    cout<<ans;
    return 0;
}