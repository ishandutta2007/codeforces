#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

int a[MAXN];

int p1[MAXN], p2[MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);
    int h;
    cin >> h;
    int n = 0;
    for (int i = 0; i <= h; ++i){
        cin >> a[i];
        n += a[i];
    }

    bool good = true;
    for (int i = 0; i < h; ++i){
        good &= (a[i] == 1 || a[i + 1] == 1);
    }

    if (good){
        cout << "perfect\n";
        return 0;
    }

    p1[0] = p2[0] = 0;
    int have = 1;
    for (int i = 1; i <= h; ++i){
        if (a[i - 1] > 1 && a[i] > 1){
            for (int j = have; j < have + a[i]; ++j){
                p1[j] = p2[j] = (have - 1) + 1;
            }
            p2[have] = (have - 2) + 1;
            have += a[i];
        }
        else{
            for (int j = have; j < have + a[i]; ++j){
                p1[j] = p2[j] = (have - 1) + 1;
            }
            have += a[i];
        }
    }

    cout << "ambiguous\n";
    for (int i = 0; i < n; ++i){
        cout << p1[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i){
        cout << p2[i] << ' ';
    }

    return 0;
}