#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int n,m,a[5005],b[5005],gcd_precalc[5005];
map<int,int> fp,mp;

int gcd(int aa, int bb) {
    if (bb) return gcd(bb, aa % bb);
    return aa;
}

int f(int num) {
    if (num <= 1) return 0;
    if (fp[num]) return fp[num];

    int i = 2, qqq = sqrt(num);
    for (; i <= qqq; ++i) {
        if (num % i == 0) break;
    }
    if (i > qqq) i = num;
    if (!fp[num]) {
        if (mp[i])
            fp[num] = f(num / i) - 1;
        else fp[num] = f(num / i) + 1;
    }
    return fp[num];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d",&b[i]);
        mp[b[i]] = 1;
    }

    gcd_precalc[0] = a[0];
    for (int i = 1; i < n; ++i)
        gcd_precalc[i] = gcd(gcd_precalc[i-1], a[i]);

    for (int i = n-1; i >= 0; --i) {
        int val = f(gcd_precalc[i]);
        if (val < 0) {
            for (int j = 0; j <= i; ++j) {
                a[j] /= gcd_precalc[i];
                gcd_precalc[j] /= gcd_precalc[i];
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += f(a[i]);
    }

    printf("%d",res);

    return 0;
}