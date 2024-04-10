#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt();
    int m = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = nxt();

    if (m == 1){
        puts("1");
        return 0;
    }

    vector<double> p(n * m + 1111), pr(n * m + 1111, 1.0);
    p[0] = 1;
    int cnt = 1;
    for (int i = 0; i < n; i++){
        cnt += m;
        for (int j = 0; j < cnt; j++){
            double r = (j - 1 >= 0 ? pr[j - 1] : 0);
            double l = (j - m - 1 >= 0 ? pr[j - m - 1] : 0);
            p[j] = (r - l) / (m - 1);
        }
        for (int j = a[i]; j < cnt; j++)
            p[j] -= (pr[j - a[i]] - (j == a[i] ? 0 : pr[j - a[i] - 1])) / (m - 1);
        pr[0] = p[0];
        for (int j = 1; j < cnt; j++)
            pr[j] = p[j] + pr[j - 1];

        // for (int i = 0; i < cnt; i++)
        //  cerr << p[i] << " ";
        // cerr << "\n";
        // for (int i = 0; i < cnt; i++)
        //  cerr << pr[i] << " ";
        // cerr << "\n";
    }
    int s = accumulate(all(a), 0);
    cout << setprecision(10) << fixed;
    double ans = 0;
    for (int i = 0; i < s; i++)
        ans += p[i];
    cout << ans * (m - 1) + 1 << "\n";

    return 0;
}