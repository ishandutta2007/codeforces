#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
typedef long long llong;

int t;
int n;
multiset<llong> a;
vector<llong> pieces;

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        llong A = 0;
        a.clear();
        for (i=1;i<=n;i++)
        {
            llong num;
            scanf("%lld", &num);
            a.insert(num);
            A += num;
        }

        pieces.clear();
        pieces.push_back(A);

        bool good = true;
        while(!pieces.empty() && pieces.size() <= n)
        {
            llong p = pieces.back();
            pieces.pop_back();

            auto it = a.find(p);

            /// Split
            if (it == a.end())
            {
                if (p < 2)
                {
                    good = false;
                    break;
                }

                pieces.push_back(p / 2);
                pieces.push_back(p - p / 2);
            }
            else /// Consume
            {
                a.erase(it);
            }
        }

        if (!pieces.empty() || !a.empty())
            good = false;

        if (good)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}