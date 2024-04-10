#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, maxm = 300010, SZ = 300;
int n, m, a[maxn], pre[maxn], nxt[maxn], ql[maxm], qr[maxm], ans[maxm];
int bel[maxn], bl[maxn], br[maxn], buc[maxn];
int L[maxn], R[maxn], foo[maxn], a1[maxn / SZ + 10][SZ + 10][SZ + 10], a2[maxn / SZ + 10][SZ + 10][SZ + 10];
vector<int> A, B[maxn / SZ + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        br[bel[i] = (i - 1) / SZ + 1] = i;
        if (!bl[bel[i]]) bl[bel[i]] = i;
    }
    vector<int> V(a + 1, a + n + 1);
    V.push_back(-1), sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
    }
    memset(L, 0x3f, sizeof(L));
    memset(R, 0x3f, sizeof(R));
    for (int k = 1; k <= bel[n]; k++) {
        for (int i = bl[k]; i <= br[k]; i++) {
            if (i > bl[k]) memcpy(a1[k][i - bl[k]], a1[k][i - bl[k] - 1], sizeof(a1[k][i - bl[k]]));
            a1[k][i - bl[k]][i - bl[k] + 1] = a[i];
            sort(a1[k][i - bl[k]] + 1, a1[k][i - bl[k]] + i - bl[k] + 2);
        }
        for (int i = br[k]; i >= bl[k]; i--) {
            if (i < br[k]) memcpy(a2[k][br[k] - i], a2[k][br[k] - i - 1], sizeof(a2[k][br[k] - i]));
            a2[k][br[k] - i][br[k] - i + 1] = a[i];
            sort(a2[k][br[k] - i] + 1, a2[k][br[k] - i] + br[k] - i + 2);
        }
        B[k] = vector<int>(a + bl[k], a + br[k] + 1);
        sort(B[k].begin(), B[k].end());
        B[k].resize(unique(B[k].begin(), B[k].end()) - B[k].begin());
    }
    scanf("%d", &m);
    for (int $ = 1, l, r; $ <= m; $++) {
        scanf("%d %d", &l, &r);
        ql[$] = l, qr[$] = r, ans[$] = INT_MAX;
        if (bel[l] == bel[r]) {
            for (int i = l; i <= r; i++) buc[a[i]]++;
            A.clear();
            for (int x : B[bel[l]]) {
                if (buc[x] > 1) { ans[$] = 0; break; }
                for (int i = 1; i <= buc[x]; i++) A.push_back(x);
            }
            for (int i = l; i <= r; i++) buc[a[i]]--;
        } else {
            A.resize(br[bel[l]] - l + 1 + r - bl[bel[r]] + 1);
            merge(a2[bel[l]][br[bel[l]] - l] + 1, a2[bel[l]][br[bel[l]] - l] + br[bel[l]] - l + 2,
                a1[bel[r]][r - bl[bel[r]]] + 1, a1[bel[r]][r - bl[bel[r]]] + r - bl[bel[r]] + 2, A.begin());
        }
        for (int i = 1; i < A.size() && ans[$]; i++) {
            ans[$] = min(ans[$], abs(V[A[i]] - V[A[i - 1]]));
        }
    }
    for (int k = 1; k <= bel[n]; k++) {
        memset(pre, 0, sizeof(pre));
        memset(nxt, 0, sizeof(nxt));
        for (int i = bl[k]; i <= br[k]; i++) {
            pre[a[i]] = nxt[a[i]] = a[i];
        }
        for (int i = 1; i <= V.size(); i++) {
            if (!pre[i]) pre[i] = pre[i - 1];
        }
        for (int i = V.size(); i; i--) {
            if (!nxt[i]) nxt[i] = nxt[i + 1];
        }
        for (int i = br[k] + 1; i <= n; i++) {
            int mn = INT_MAX;
            if (pre[a[i]]) mn = min(mn, abs(V[a[i]] - V[pre[a[i]]]));
            if (nxt[a[i]]) mn = min(mn, abs(V[a[i]] - V[nxt[a[i]]]));
            if (i == bl[bel[i]]) L[i] = mn;
            else L[i] = min(L[i - 1], mn);
        }
        L[br[k]] = INT_MAX;
        vector<int> A(a + bl[k], a + br[k] + 1);
        sort(A.begin(), A.end()), B[k] = A;
        B[k].resize(unique(B[k].begin(), B[k].end()) - B[k].begin());
        for (int i = 1; i < A.size(); i++) {
            L[br[k]] = min(L[br[k]], abs(V[A[i]] - V[A[i - 1]]));
        }
        for (int i = bl[k] - 1; i; i--) {
            int mn = INT_MAX;
            if (pre[a[i]]) mn = min(mn, abs(V[a[i]] - V[pre[a[i]]]));
            if (nxt[a[i]]) mn = min(mn, abs(V[a[i]] - V[nxt[a[i]]]));
            if (i == br[bel[i]]) R[i] = mn;
            else R[i] = min(R[i + 1], mn);
        }
        for (int i = bl[k]; i <= br[k]; i++) {
            if (i > bl[k]) memcpy(a1[k][i - bl[k]], a1[k][i - bl[k] - 1], sizeof(a1[k][i - bl[k]]));
            a1[k][i - bl[k]][i - bl[k] + 1] = a[i];
            sort(a1[k][i - bl[k]] + 1, a1[k][i - bl[k]] + i - bl[k] + 2);
        }
        for (int i = br[k]; i >= bl[k]; i--) {
            if (i < br[k]) memcpy(a2[k][br[k] - i], a2[k][br[k] - i - 1], sizeof(a2[k][br[k] - i]));
            a2[k][br[k] - i][br[k] - i + 1] = a[i];
            sort(a2[k][br[k] - i] + 1, a2[k][br[k] - i] + br[k] - i + 2);
        }
        for (int i = k; i <= bel[n]; i++) {
            foo[i] = min(i == k ? INT_MAX : foo[i - 1], L[br[i]]);
        }
        for (int i = 1; i <= m; i++) if (ans[i] && k > bel[ql[i]] && k < bel[qr[i]]) {
            ans[i] = min({ans[i], R[ql[i]], L[qr[i]]});
            if (bel[qr[i]] > k) ans[i] = min(ans[i], foo[bel[qr[i]] - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}