#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int main()
{
    LL n, k;
    cin >> n >> k;
    vector<pair<LL, int> > a;
    for (int i = 2; 1ll * i * i <= n; i++){
        if (n % i == 0){
            a.pb(mp(i, 0));
            while (n % i == 0){
                a[a.size() - 1].y++;
                n /= i;
            }
        }
    }
    if (n > 1){
        a.pb(mp(n, 1));
    }
    vector<pair<LL, LL> > d;
    vector<int> b(a.size(), 0);
    int i = a.size() - 1;
    LL q = 1, w = 1;
    while (i >= 0){
        d.pb(mp(q, w));
        while (i >= 0 && b[i] == a[i].y){
            while (b[i] > 0){
                b[i]--;
                q /= a[i].x;
            }
            w /= (a[i].y + 1);
            i--;
        }
        if (i >= 0){
            b[i]++;
            q *= a[i].x;
            w = w / b[i] * (b[i] + 1);
            i = a.size() - 1;
        }
    }
    sort(all(d));
    if (a.size() == 0){
        cout << 1 << "\n";
        return 0;
    } else
    if (k > 100000){
        for (int i = 0; i < 100000; i++) cout << "1 ";
        cout << "\n";
        return 0;
    } else {
        vector<vector<int> > boo(d.size());
        int cnt = d.size();
        for (int i = 0; i < cnt; i++){
            for (int j = 1; j <= i; j++){
                if (d[i].x % d[j].x == 0) boo[i].pb(j);
            }
        }
        vector<int> ar(1, d.size() - 1), dr;
        vector<int> br(1, 0), cr;
        for (int i = 0; i < k; i++){
            dr.resize(0);
            cr.resize(0);
            int C = 0;
            for (int j = 0; j < ar.size() && C <= 100000; j++){
                cr.pb(br[j] + 1);
                C += cr.back();
                for (int ij = 0; ij < boo[ar[j]].size(); ij++){
                    dr.pb(boo[ar[j]][ij]);
                    C++;
                    if (ij > 0) cr.pb(0);
                }
            }
            swap(ar, dr);
            swap(br, cr);
        }
        int ind = 0;
        for (int i = 0; i < ar.size() && ind < 100000; i++){
            for (int j = 0; j < br[i] && ind < 100000; j++, ind++){
                cout << "1 ";
            }
            if (ind < 100000){
                cout << d[ar[i]].x << " ";
                ind++;
            }
        }
    }

    return 0;
}