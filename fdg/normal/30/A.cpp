#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <cmath>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    double a,b,n;
    cin >> a >> b >> n;
    if (a==0)
    {
        if (b==0) cout << 5 << endl;
        else cout << "No solution\n";
        return 0;
    }
    b/=a;
/*  if (b/a!=((long)(b/a)))
    {
        cout << "No solution\n";
        return 0;
    }
*/  bool sgn=false;
    if (b<0)
    {
        b=-b;
        sgn=true;
    }
    bool ans=false; int k=0;
    for(int q=pow(b,1/n)-2;q<=pow(b,1/n)+2;q++)
    {
        if (q<0) continue;
        double r=q;
        for(int i=2;i<=n;i++)
            r*=q;
        if (r==b)
        {
            if (sgn)
            {
                if (((int)n)%2==1)
                {
                    ans=true;
                    k=-q;
                }
            }
            else
            {
                ans=true;
                k=q;
            }
        }
    }
    if (ans)
    {
        cout << k << endl;
    }
    else cout << "No solution\n";
    return 0;
}