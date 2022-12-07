#include <bits/stdc++.h>

using namespace std;

const int N = 100'007;

int l, n;
int in[N];
int suf[N];
int result[N];

bool check(int len)
{
    int pref_max = -len;
    for (int i = 1; i <= n + 1; ++i) {
        if (in[i] - 1LL * i * len < pref_max) {
            return false;
        }

        pref_max = max(pref_max, in[i] - (i + 1) * len);
    }

    return true;
}

int find_min_len()
{
    int s = 1, e = l;
    while (s < e) {
        int mid = (s + e + 1) / 2;
        if (check(mid)) {
            s = mid;
        } else {
            e = mid - 1;
        }
    }

    return s;
}

bool get(int min_len, int max_len)
{
    suf[n + 1] = l - (n + 1) * min_len;
    for (int i = n; i >= 1; --i) {
        suf[i] = min(suf[i + 1], in[i] - i * min_len);
    }

    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        int nxt = cur + max_len;
        nxt = min(nxt, suf[i + 1] + (i + 1) * min_len);

        if (nxt < in[i]) {
            return false;
        }

        cur = nxt;
        result[i] = nxt;
    }

    return result[n] == l;
}

int find_ans(int min_len)
{
    int s = 0, e = l - min_len;
    while (s < e) {
        int mid = (s + e) / 2;
        if (get(min_len, min_len + mid)) {
            e = mid;
        } else {
            s = mid + 1;
        }
    }

    return s;
}

void print_ans(int len, int diff)
{
    get(len, len + diff);
    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", result[i - 1], result[i]);
    }
}

int main()
{
    scanf("%d %d", &l, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
    }

    in[n + 1] = l;
    
    int min_len = find_min_len();
    int ans_len = find_ans(min_len);
//    fprintf(stderr, "min = %d, ans = %d\n", min_len, ans_len);
    print_ans(min_len, ans_len);
    return 0;
}