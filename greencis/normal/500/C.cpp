#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,w[9999],b[9999],u[9999],prior[9999],ans;
vector<int> st;

struct entry {
    int idx,w,prior;
} e[9999];

int comp(entry a, entry b) {
    return a.w == b.w ? a.idx < b.idx : a.w < b.w;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&w[i]);
        e[i].w = w[i];
        e[i].idx = i;
    }
    sort(e,e+n,comp);
    for (int i = 0; i < n; ++i) {
        prior[e[i].idx] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d",&b[i]); --b[i];
        if (!u[b[i]]) st.push_back(b[i]), u[b[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (!u[i]) st.push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        int idx = -1;
        for (int j = 0; j < n; ++j) {
            if (st[j] == b[i]) {
                idx = j;
                break;
            }
        }
        for (int j = 0; j < idx; ++j)
            ans += w[st[j]];
        st.erase(st.begin() + idx);
        st.insert(st.begin(), b[i]);
    }

    printf("%d",ans);

    return 0;
}