#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

int a[1000005];
int ans[1000005];
bool c[1000005];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, T;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int x;
        scanf("%d", &x);
        c[x - 1] = true;
    }
    vector<int> st;
    for (int i = N - 1; i >= 0; --i) {
        if (c[i] || st.empty() || a[st.back()] != a[i]) {
            st.push_back(i);
        } else {
            ans[i] = 1;
            ans[st.back()] = -1;
            st.pop_back();
        }
    }
   
    if (st.empty()) {
        printf("YES\n");
        for (int i = 0; i < N; ++i) {
            printf("%d ", a[i] * ans[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }

	return 0;
}