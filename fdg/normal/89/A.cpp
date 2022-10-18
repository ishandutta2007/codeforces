#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k,nums[10001]={0};
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        cin >> nums[i];
    if (n&1)
    {
        if ((n+1)/2>m)
        {
            cout << 0 << endl;
            return 0;
        }
        int one=m/((n+1)/2);
        /*for(int i=1;i<=(n+1)/2;i+=2)
        {
            if (i+(n-i)/2<=m) one=i;
        }*/
        ll kol=1LL*k*one,ret=0;
        int mn=nums[0];
        for(int i=2;i<n;i+=2)
            mn=min(nums[i],mn);
        for(int i=0;i<k;i++)
            if (mn>0)
            {
                ret+=min(one,mn);
                mn-=one;
            } else break;
        cout << ret << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}