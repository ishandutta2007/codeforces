#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mod 1000000007
#include <vector>
using namespace std;
int a[1000000];
int n;
long long all;
vector<int>neg, pos;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n ; i ++) {
        double v;
        scanf("%lf", &v);
        if (abs(v - int(v)) < 1e-6) {
            a[i] = int(v);
            all += a[i];
            continue;
        }
        if (abs(v - int(v) - 1) < 1e-6) {
            a[i] = int(v) + 1;
            all += a[i];
            continue;
        }

        if (abs(v - int(v) + 1) < 1e-6) {
            a[i] = int(v) - 1;
            all += a[i];
            continue;
        }
        a[i] = floor(v);
        all += a[i];
        if (v < 0)
            neg.push_back(i);
        else
            pos.push_back(i);
    }
    for (auto u: neg)
        if (all == 0){
            break;
        } else {
            all += 1;
            a[u] += 1;
        }
    for (auto u:pos)
        if (all == 0){
            break;
        } else {
            all += 1;
            a[u] += 1;
        }

    for (int i = 0;  i < n;  i ++)
        printf("%d\n",a[i]);
    return 0;
}