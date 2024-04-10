#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

int v[100005]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    ll ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    int l=1;
    v[n]=2000000000;
    for(int i=1;i<=n;i++)
        if (v[i]!=v[i-1])
        {
            ans+=1LL*l*(l+1)/2;
            l=1;
        } else l++;
    cout << ans << endl;
    return 0;
}