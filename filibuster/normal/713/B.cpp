#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
5 10
99.99
*/

pii qp[2], qq[2];

//int query(int x1, int y1, int x2, int y2) {
//    int res =0;
//    for(int i  =0; i < 2; i++) {
//        if(x1 <= qp[i].f && qq[i].f <= x2 && y1 <= qp[i].s && qq[i].s <= y2)
//            res++;
//    }
//
////    cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << ' ' << res << endl;
////    cout << x1 << ' ' << qp[0].f << ' ' << qq[0].f << ' ' << x2 << ' ' << y1 << ' ' << qp[0].s << ' ' <<
////                qq[0].s << ' ' << y1 ,
//
//    return res;
//}

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
    int res;
    cin >> res;
    return res;
}

pii p[2], q[2];

int cnt(int x1, int y1, int x2, int y2) {
    int res =0;
    for(int i  =0; i < 2; i++) {
        if(q[i].f != -1 && x1 <= p[i].f && q[i].f <= x2 && y1 <= p[i].s && q[i].s <= y2)
            res++;
    }

    return res;
}


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    qp[0] = {1, 1};
    qq[0] = {1, 1};
    qp[1] = {3, 4};
    qq[1] = {4, 4};

    p[0] = p[1] = q[0] = q[1] = {-1, -1};

    for(int i = 0; i < 2; i++) {
        {
            int l = -1, r = n - 1;
            while(r - l > 1) {
                int m = (l + r) / 2;

                if(query(0, 0, n - 1, m) - cnt(0, 0, n - 1, m) > 0)
                    r = m;
                else
                    l = m;
            }

            q[i].s = r;
        }

        {
            int l = 0, r = q[i].s + 1;
            while(r - l > 1) {
                int m = (l + r) / 2;

//                cout << i << ' ' << l << ' '<< m << ' ' << r << endl;

                if(query(0, m, n - 1, q[i].s) - cnt(0, m, n - 1, q[i].s) > 0)
                    l = m;
                else
                    r = m;

//                cout << i << ' ' << l << ' '<< m << ' ' << r << endl;
            }

            p[i].s = l;
        }

        {
            int l = 0, r = n;
            while(r - l > 1) {
                int m = (l + r) / 2;

                if(query(m, p[i].s, n - 1, q[i].s) - cnt(m, p[i].s, n - 1, q[i].s) > 0)
                    l = m;
                else
                    r = m;
            }

            p[i].f = l;
        }

        {
            int l = p[i].f - 1, r = n - 1;
            while(r - l > 1) {
                int m = (l + r) / 2;

                if(query(p[i].f, p[i].s, m, q[i].s) - cnt(p[i].f, p[i].s, m, q[i].s) > 0)
                    r = m;
                else
                    l = m;
            }

            q[i].f = r;
        }
    }

    cout << "! " << p[0].f + 1 << ' ' << p[0].s + 1 << ' ' << q[0].f + 1 << ' ' << q[0].s + 1 << ' '
                 << p[1].f + 1 << ' ' << p[1].s + 1 << ' ' << q[1].f + 1 << ' ' << q[1].s + 1 << endl;
}