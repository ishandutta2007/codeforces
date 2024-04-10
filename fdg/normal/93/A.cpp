#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#pragma comment(linker, "/STACK:65777216")

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if (m==1)
    {
        cout << 1 << endl;
        return 0;
    }
    int r1=(a-1)/m,r2=(b-1)/m;
    if (b+1>n) b+=m-(b-1)%m-1;
    if (r1==r2) cout << 1 << endl;
    else
    {
        if (r1+1==r2)
        {
            if ((b%m==0&&a%m==1)) cout << 1 << endl;
            else cout << 2 << endl;
        }
        else
        {
            int res=1;
            if (a%m!=1) res++;
            if (b%m!=0) res++;
            if ((a)%m==(b+1)%m) res=min(res,2);
            cout << res << endl;
        }
    }
    return 0;
}