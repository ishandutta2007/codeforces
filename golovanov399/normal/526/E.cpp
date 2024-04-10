#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int df(int x, int y, int n){
    return y - x + (x <= y ? 0 : n);
}

int main(){

    int n;
    scanf("%d", &n);
    int q;
    scanf("%d", &q);
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    long long s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    while (q--){
        long long b;
        cin >> b;
        if (b >= s){
            cout << 1 << "\n";
            continue;
        }
        vector<int> nx(n);
        int cur = 0;
        long long cursum = 0;
        for (int i = 0; i < n; i++){
            while (cursum + a[cur] <= b){
                cursum += a[cur++];
                if (cur == n)
                    cur -= n;
            }
            nx[i] = cur;
            cursum -= a[i];
        }
        vector<int> ans(n), lst(n);
        for (int i = n - 1; i >= 0; i--){
            if (nx[i] < i){
                ans[i] = 1;
                lst[i] = nx[i];
            } else {
                ans[i] = 1 + ans[nx[i]];
                lst[i] = lst[nx[i]];
            }
        }
        cur = 0;
        while (cur < nx[cur])
            cur = nx[cur];
        int res = ans[0];
        for (int i = 1; i <= nx[0]; i++){
            if (lst[i] >= i)
                res = min(res, ans[i]);
            else
                res = min(res, ans[i] + 1);
        }
        cout << res << "\n";
    }

    return 0;
}