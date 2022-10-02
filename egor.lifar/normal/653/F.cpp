#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


#define all(c) (c).begin(), (c).end()
const int MAXN = 1000228;
const int LOGN = 20;
int n;
char s[MAXN];
int a[MAXN];
int len;
pair<pair<int, int>, int> p[MAXN];
int ranks[LOGN][MAXN];
int order[MAXN];
int lcp[MAXN];


inline void resort(int g) {
    sort(p + 1, p + 1 + len);
    int cntOfRanks = 1;
    for (int i = 1; i <= len; i++){
        if (i > 1 && p[i - 1].first != p[i].first) {
            cntOfRanks++;
        }
        ranks[g][p[i].second] = cntOfRanks;
    }
}


void buildSuffixArray() {
    len = n;
    for(int i = 1; i <= len; i++) {
        p[i] = make_pair(make_pair(s[i], 0), i);
    }
    resort(0);
    for (int g = 0; g + 1 < LOGN; g++) {
        int d = 1 << g;
        for(int i = 1; i <= len; i++) {
            p[i] = make_pair(make_pair(ranks[g][i], i + d <= len? ranks[g][i + d] : -1), i);
        }
        resort(g + 1);
    }
    for(int i = 1; i <= len; i++){
        order[ranks[LOGN - 1][i]] = i;
    }
    lcp[0] = 0;
    for(int i = 1; i < len; i++){
        int cnow = order[i];
        int cnext = order[i + 1];
        lcp[i] = 0;
        for (int j = LOGN - 1; j >= 0; j--) {
            int d = 1 << j;
            if (cnow + d - 1 <= len && cnext + d - 1 <= len && ranks[j][cnow] == ranks[j][cnext]) {
                cnow += d;
                cnext += d;
                lcp[i] += d;
            }
        }
    }
}


vector<int> locs[2 * MAXN];


int isBetween(int x, int l, int r) {
    if (l > r) {
        return 0;
    }
    return upper_bound(all(locs[x + MAXN]), r) - lower_bound(all(locs[x + MAXN]), l);
}


int toR[MAXN];


int main(){
    scanf("%d", &n);
    scanf("%s", s + 1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1];
        if (s[i] == '(') {
            a[i] += 1;
        } else {
            a[i] -= 1;
        }
    } 
    buildSuffixArray();
    for (int i = 0; i <= n; i++) {
        locs[a[i] + MAXN].push_back(i);
    }
    vector<int> st;
    for (int i = n; i >= 0; i--) {
        while (st.size() && a[st.back()] >= a[i]) {
            st.pop_back();
        }
        toR[i] = (st.size()? st.back() : n + 1);
        st.push_back(i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int from = order[i] + lcp[i - 1];
        int to = toR[order[i] - 1] - 1;
        int good = isBetween(a[order[i] - 1], from, to);
        ans += good;
    }
    cout << ans << endl;
    return 0;
}