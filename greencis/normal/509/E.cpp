#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

char s[999999];
int n;
ld ans;
ld obr1[999999];
ld sum_obr1[999999];
ld sum_obr1_arithm[999999];

int main()
{
    obr1[1] = sum_obr1[1] = sum_obr1_arithm[1] = ld(1);
    for (int i = 2; i <= 899999; ++i) {
        obr1[i] = ld(1) / ld(i);
        sum_obr1[i] = sum_obr1[i-1] + obr1[i];
        sum_obr1_arithm[i] = sum_obr1_arithm[i-1] + sum_obr1[i-1];
    }

    scanf("%s",s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A' || s[i] == 'O' || s[i] == 'I' || s[i] == 'E' || s[i] == 'U' || s[i] == 'Y') {
            int l = i;
            int r = n - i - 1;
            ans += n - (n-r-1 - ld(sum_obr1[n] - sum_obr1[r+1]) * ld(r+1)) -
                       (n-l-1 - ld(sum_obr1[n] - sum_obr1[l+1]) * ld(l+1));
        }
    }
    cout.precision(17);
    cout << fixed << ans;

    return 0;
}