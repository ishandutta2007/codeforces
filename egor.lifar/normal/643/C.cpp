#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>


using namespace std;


int n, k;
double wcz;
long double sum[200007];
long double rev[200007];
long double pre[200007];
long double inf;
long double dpo[200007];
long double dpn[200007];
long double x[200007];
long double y[200007];
int l;
vector<int> st;


inline long double vec(int s, int a, int b) {
    return (x[a] - x[s]) * (y[b] - y[s]) - (x[b] - x[s]) * (y[a] - y[s]);
}


int main() {
    inf = 1000000000.0;
    inf *= inf;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &wcz);
        sum[i] = wcz;
        pre[i] = pre[i - 1] + sum[i - 1] / sum[i] + 1.0;
        rev[i] = 1.0 / sum[i] + rev[i - 1];
        sum[i] += sum[i - 1];
    }
    for (int i = 1; i <= n; i++)  {
        dpn[i] = pre[i];
    }
    for (int h = 2; h <= k; h++)  {
        for (int i = 0; i <= n; i++) {
            dpo[i] = dpn[i];
            dpn[i] = pre[i];
            x[i] = dpo[i] + rev[i] * sum[i] - pre[i];
            y[i] = sum[i];
        }
        st.clear();
        l = 0;
        for (int i = 1; i <= n; i++) {
            while (st.size() > 1 && vec(st[st.size() - 2], st[st.size() - 1], i - 1) >= 0) {
                st.pop_back();
            }
            l = min(l, (int)st.size() - 1);
            l = max(l, 0);
            st.push_back(i - 1);
            while (l + 1 < (int)st.size() && 1 * x[st[l + 1]] - rev[i] * y[st[l + 1]] <= 1 * x[st[l]] - rev[i] * y[st[l]]) {
                l++;
            }
            dpn[i] += 1 * x[st[l]] - rev[i] * y[st[l]];
        }
    }
    printf("%.10lf\n", (double)dpn[n]);
    return 0;
}