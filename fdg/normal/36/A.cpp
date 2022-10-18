#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <set>

#define ll long long

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,last=-1,d=-1;
    char a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if (a=='1')
        {
            if (last==-1) last=i;
            else
                if (d==-1) d=i-last;
                else
                {
                    if (d!=i-last)
                    {
                        cout << "NO\n";
                        return 0;
                    }
                }
            last=i;
        }
    }
    cout << "YES\n";
    return 0;
}