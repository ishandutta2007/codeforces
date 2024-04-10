#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    long long ans = 0;
    vector<pair<int, int> > qw;
    for (itn i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            qw.pb(mp(i, j + 1));
    int m = qw.size();
    vector<int> ar(k, 0);
    while (1){
        vector<int> q(p);
        for (itn i = 0; i < k; i++){
            reverse(q.begin() + qw[ar[i]].x, q.begin() + qw[ar[i]].y);
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (q[i] > q[j])
                    ans++;
        int i = k - 1;
        while (i >= 0 && ar[i] == m - 1){
            ar[i--] = 0;
        }
        if (i < 0)
            break;
        else
            ar[i]++;
    }
    long double res = ans;
    for (int i = 0; i < k; i++)
        res /= m;
    cout << setprecision(10) << fixed;
    cout << res << "\n";

    return 0;
}