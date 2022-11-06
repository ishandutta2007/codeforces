#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;
typedef unsigned long long ulint;

using namespace std;

const int maxV = 70016;
const int kk = maxV/64;
const int maxn = 70010;

int a[maxn];
ulint can[kk];
int next[maxV];
int istop[maxn];
int have[maxn];

int get_can(int x)
{
    return x >= 0 && ((can[x/64] & (1ULL<<(x%64))) != 0);
}


inline void update_next(int j, ulint news, int id)
{
    while (news) {
        ulint bitv = news & (-news);
        int i = __builtin_ctzll(bitv);

        int pos = j * 64 + i;

        next[pos] = id;

        news -= bitv;
    }
}

int main(int argc, char ** argv)
{
    int n, s;

    scanf("%d %d", &n, &s);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < kk; i++)
        can[i] = 0;

    int maxid = max_element(a, a+n) - a;
    int maxv = a[maxid];

    memset(next, -1, sizeof(next));

    ulint un = 1ULL;

    can[0] |= un << 0;
    next[0] = -2;

    for (int i = 0; i < n; i++) {
        if (i == maxid) continue;
        for (int j = kk-1; j >= 0; j--) {
            int start = j * 64, end = (j+1) * 64;
            int start2 = j * 64 + a[i], end2 = (j+1) * 64 + a[i];

            lint rest = start2 % 64;
            
            unsigned long long canj = can[j];

            if (start2/64 < kk) {
                ulint news = (canj << rest) & (~can[start2 / 64]);
                can[start2 / 64] |= canj << rest;
                update_next(start2/64, news, i);
            }
            
            if (start2/64+1 < kk && rest) {
                ulint news = (canj >> (64-rest)) & (~can[start2 / 64 + 1]);
                can[start2 / 64 + 1] |= canj >> (64-rest);
                update_next(start2 / 64 + 1, news, i);
            }
        }
    }

    if (maxv > s || next[s-maxv] == -1) {
        printf("-1\n");
    } else {
        vector <int> tops;

        tops.push_back(maxid);
        for (int now = s-maxv; now > 0; now -= a[next[now]])
            tops.push_back(next[now]);

        memset(istop, 0, sizeof(istop));
        
        for (int j = 0; j < tops.size(); j++)
            istop[tops[j]] = 1;

        vector <pair <int, int> > inside;

        for (int j = 0; j < n; j++)
            if (!istop[j])
                inside.push_back(make_pair(a[j], j));
        sort(inside.begin(), inside.end());

        memset(have, -1, sizeof(have));

        for (int j = 0; j < inside.size(); j++) {
            if (j+1 < inside.size()) {
                have[inside[j+1].second] = inside[j].second;
            } else {
                have[maxid] = inside[j].second;
            }
        }

        for (int i = 0; i < n; i++) {
            int extra = 0;

            int sumnow = 0;
            if (have[i] != -1)
                sumnow += a[have[i]];
            extra = a[i] - sumnow;

            printf("%d %d", extra, have[i] != -1);
            if (have[i] != -1)
                printf(" %d", have[i]+1);
            printf("\n");
        }
    }

    return 0;
}