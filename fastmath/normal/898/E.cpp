#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 7;

int a[MAXN];
int q[MAXN];
set <int> sq;

int get_cost(int n){
    int l = -1;
    int r = MAXN;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (q[m] < n){
            l = m;
        }
        else{
            r = m;
        }
    }

    return min(abs(n - q[l]), abs(n - q[r]));
}

bool is_q(int n){
    return sq.find(n) != sq.end();
}

signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cout.precision(40);

    for (int i = 0; i < MAXN; ++i){
        sq.insert(i * i);
        q[i] = i * i;
    }

    int n;
    cin >> n;
    int q_count = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        q_count += is_q(a[i]);
    }


    if (q_count <= n / 2){
        vector <int> cost;
        for (int i = 0; i < n; ++i){
            if (!is_q(a[i])){
                cost.push_back(get_cost(a[i]));
            }
        }

        sort(cost.begin(), cost.end());

        int want = n / 2 - q_count;
        int ans = 0;
        for (int i = 0; i < want; ++i){
            ans += cost[i];
        }

        cout << ans;
    }
    else{
        vector <int> cost;
        for (int i = 0; i < n; ++i){
            if (is_q(a[i])){
                if (a[i] == 0){
                    cost.push_back(2);
                }
                else{
                    cost.push_back(1);
                }
            }
        }

        sort(cost.begin(), cost.end());

        int want = q_count - n / 2;
        int ans = 0;
        for (int i = 0; i < want; ++i){
            ans += cost[i];
        }

        cout << ans;
    }

    return 0;
}