#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
#include <ctime>
#include <set>

#define ll unsigned long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,c,a,last=0,ans=0;
    cin >> n >> k >> c;
    while(cin >> a)
    {
        while(last+k<a)
        {
            last+=k;
            ans++;
        }
        last=a; ans++;
    }
    while(last+k<=n)
    {
        last+=k;
        ans++;
    }
    cout << ans << endl;
    return 0;
}