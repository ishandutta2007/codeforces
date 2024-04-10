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
#include<ctime>
#include<utility>
#include<vector>
using namespace std; 
int b[111],ans[111],n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        for(int j=b[i];j<=n;j++)if(ans[j]==0)ans[j]=b[i];
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}