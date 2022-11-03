#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const li INF = 1e18 + 13;

/*
1 1 1
1 1 1
*/

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> a[4];
    for(int i = 0; i < n; i++) {
        int x, a1, b1;
        cin >> x >> a1 >> b1;

        a[a1 * 2 + b1].emplace_back(x, i);
    }

    if(a[3].size() + min(a[1].size(), a[2].size()) < k) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < 4; i++)
        sort(a[i].begin(), a[i].end());

//    vector<li> sa(a.size() + 1, 0), sb(b.size() + 1, 0);
//    for(int i = 1; i <= a.size(); i++) {
//        sa[i] = sa[i - 1] + a[i - 1];
////        cout << "sa " << i << ' ' << sa[i] << endl;
//    }
//
//    for(int i = 1; i <= b.size(); i++) {
//        sb[i] = sb[i - 1] + b[i - 1];
//    }

    li cur = 0;
    li ans = INF;

    int j[] = {0, 0, 0, 0};
    int ja[] = {0, 0, 0, 0};
    li sum[] = {0ll, 0ll, 0ll, 0ll};

    int x = min(int(a[3].size()), max(m, k));

    for(int i = 0; i < x; i++) {
        sum[3] += a[3][i].f;
    }
    j[3] = x;

    for(int i = 0; i < k - x; i++) {
        sum[1] += a[1][j[1]].f;
        sum[2] += a[2][j[2]].f;
        j[1]++;
        j[2]++;
    }

//    for(j[1] = 0, j[2] = 0; j[1] < k - x; j[1]++, j[2]++) {
//        sum[1] += a[1][j[1]];
//        sum[2] += a[2][j[2]];
//    }



    while(j[0] + j[1] + j[2] + j[3] < m) {
        int mn = -1;
        for(int i = 0; i < 4; i++)
            if(j[i] < a[i].size() && (mn == -1 || a[mn][j[mn]].f > a[i][j[i]].f))
                mn = i;
//            cout << "+ " << mn << ' '<< a[mn][j[mn]] << endl;
        if(mn == -1) {
            cout << -1;
            return 0;
        }
        sum[mn] += a[mn][j[mn]++].f;

    }

    {
        ans = 0;
        for(int i = 0; i < 4; i++)
            ans += sum[i];
//        cout << ans << ' ' << sum[0] << ' ' << sum[1] << ' ' << sum[2] << ' ' << sum[3] << endl;
//        cout << j[0] << ' ' << j[1] << ' ' << j[2] << ' ' << j[3] << endl;

        int s = 0;
        for(int i = 0; i < 4; i++)
            s += j[i];
        if(s != m) {
            cout << -1;
            return 0;
        }

        for(int i = 0; i < 4; i++)
            ja[i] = j[i];
    }


    for(int i = x - 1; i >= 0; i--) {
        j[3]--;
        sum[3] -= a[3][j[3]].f;

        bool fl = false;

        for(int l = 1; l < 3; l++) {
            if(j[3] + a[l].size() < k) {
                fl = true;
                break;
            }

            while(j[l] + j[3] < k) {
                sum[l] += a[l][j[l]].f;
                j[l]++;
            }
        }

        if(j[1] + j[2] + j[3] > m || fl) {
            break;
        }
//cout <<"drg " << sum[0] << ' ' << sum[1] << ' ' << sum[2] << ' ' << sum[3] << endl;
//        cout << j[0] << ' ' << j[1] << ' ' << j[2] << ' ' << j[3] << endl;
        while(j[0] + j[1] + j[2] + j[3] > m) {
            j[0]--;
            sum[0] -= a[0][j[0]].f;
        }

        while(j[0] + j[1] + j[2] + j[3] < m) {
            int mn = -1;
            for(int i = 0; i < 3; i++)
                if(j[i] < a[i].size() && (mn == -1 || a[mn][j[mn]].f > a[i][j[i]].f))
                    mn = i;

            if(mn == -1) {
                fl = true;
                break;
            }
            sum[mn] += a[mn][j[mn]++].f;
        }

        if(fl)
            break;

        int s = 0;
        for(int i = 0; i < 4; i++)
            s += j[i];
        if(s != m) {
            break;
        }

        li res = 0;
        for(int i = 0; i < 4; i++)
            res += sum[i];

        if(ans > res) {
            ans = res;
            for(int l = 0; l < 4; l++)
                ja[l] = j[l];
        }

    }

    cout << (ans < INF ? ans : -1) << endl;
    if(ans < INF) {
        for(int l = 0; l < 4; l++)
            for(int i = 0; i < ja[l]; i++)
                cout << a[l][i].s + 1 << ' ';
    }
}