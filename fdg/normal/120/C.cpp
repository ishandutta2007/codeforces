#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,a[101],ans=0;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(int j=0;j<3;j++)
        {
            if (a[i]<k)
            {
                break;
            } else a[i]-=k;
        }
        ans+=a[i];
    }
    cout << ans << endl;
    return 0;
}