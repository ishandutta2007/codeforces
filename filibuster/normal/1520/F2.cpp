#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 14;
const int B = 10;

//int A[6] = {1, 0, 1, 1, 0, 1};
//
//int qget(int l, int r) {
//    int res = 0;
//    for(int i = l; i < r; i++)
//        res += A[i];
//    return res;
//}

int qget(int l, int r) {
    cout << "? " << l + 1 << ' ' << r << endl;
    int x;
    cin >> x;

    return x;
}

void qans(int i) {
    cout << "! " << i + 1 << endl;
}

int t[N];
int a[N];

void upd(int i, int x) {
    for(; i < N; i = (i | (i + 1)))
        t[i] += x;
}

int get(int i) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

//int get(int l, int r) {
//    return get(r) - (l == 0 ? 0 : get(l - 1));
//}


int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n, t;
    cin >> n >> t;

    int k;
    cin >> k;
    k--;

    int m = 0;
    for(int i = 0; i * B < n; i++) {
        int l = i * B, r = min((i + 1) * B, n);
        a[i] = r - l - qget(l, r);
        upd(i, a[i]);
        m++;
    }

    for(int ind = 0; ind < t; ind++) {


        int i = -1;
        {
            int l = -1, r = m - 1;
            while(r - l > 1) {
                int mid = (l + r) / 2;

                if(get(mid) <= k)
                    l = mid;
                else
                    r = mid;
            }
            i = r;
        }

        int res = -1;
        {
            int l = i * B - 1, r = min(n, (i + 1) * B) - 1;
            while(r - l > 1) {
                int mid = (l + r) / 2;

//                cout << l << ' ' << mid << ' ' << r << ' ' << qget(0, mid + 1) << ' ' << k << endl;

                if(mid + 1 - qget(0, mid + 1) > k)
                    r = mid;
                else
                    l = mid;
            }
            res = r;
        }

        qans(res);
        upd(i, -1);
//        A[res] = 1;

        if(ind < t - 1) {
            cin >> k;

            k--;
        }
    }
}