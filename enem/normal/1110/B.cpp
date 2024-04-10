#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int b[n];
    int g[n-1];
    scanf("%d",&b[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&b[i]);
        g[i-1]=b[i]-b[i-1]-1;
    }
    sort(g,g+n-1);
    int ans=b[n-1]-b[0]+1;
    for(int i=0;i<k-1;i++)
    {
        ans-=g[n-2-i];
    }
    cout<<ans;
    return 0;
}