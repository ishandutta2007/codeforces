#include<iostream>
#include<vector>
#include <unordered_set>
#include <algorithm>
#include <functional>
#define mp(x, y, z) pair<long long, long long> z=make_pair(x, y)
#define pb(x, y) x.push_back(y)
#define ff(x)  if(x>0)
#define cn(x) cin>>x
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pr;
typedef vector <long long>  vl;
typedef int nt;
long long mxprm[1000005], cur[1000005];
// *
nt main ()
{
    for (nt j = 0; j <= 1000000; j++)
    {
        cur[j] = j;
    }
    for (nt j = 2; j <= 1000000; j++)
    {
        ff (cur[j] - 1)
        {
            for (nt h = 1; h*j <= 1000000; h++)
            {
                while (cur[h*j] % j == 0)
                {
                    ff (cur[h*j] - j)
                    {
                        cur[h*j] /= j;
                    }
                    ff (1 - (cur[h*j] - j))
                    {
                        cur[h*j] /= j;
                        mxprm[h*j] = j;
                    }
                }
            }
        }
    }
    ll x_2, ans = 1000000;
    cn (x_2);
    {
        for (nt j = x_2 - mxprm[x_2] + 1; j <= x_2; j++)
        {
            ff ((j - mxprm[j]))
            {
                ans = min (ans, j - mxprm[j] + 1);
            }
        }
    }
    cout << ans;

    return 0;
}