#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'001;
int p[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    p[1] = 1;
    for (int i = 2; i < N; i++) if (p[i] == 0) {
        for (int j = i; j < N; j += i) if (p[j] == 0) {
            p[j] = i;
        }
    }

    int n, k;
    cin >> n >> k;

    map<int, int> pp;
    for (; k != 1; k /= p[k]) pp[p[k]]++;

    while (n--) {
        int x;
        cin >> x;

        int cur = 2, cnt = 0;
        for (; x != 1; x /= p[x]) {
            if (cur != p[x]) {
                if (pp.count(cur) && cnt >= pp[cur]) {
                    pp.erase(cur);
                }

                cur = p[x], cnt = 0;
            }

            cnt++;
        }

        if (pp.count(cur) && cnt >= pp[cur]) {
            pp.erase(cur);
        }
    }

    cout << (pp.empty() ? "Yes" : "No");
}