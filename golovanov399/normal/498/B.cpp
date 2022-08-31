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

    int n, T;
    cin >> n >> T;
    vector<double> p(n);
    vector<int> t(n);
    for (int i = 0; i < n; i++){
        cin >> p[i] >> t[i];
        p[i] /= 100;
    }
    cerr << setprecision(5) << fixed;
    vector<double> v(T + 1), w(T + 1);
    for (int i = n - 1; i >= 0; i--){
        double val = 0;
        double qw = 1;
        for (int ij = 0; ij < t[i] - 1; ij++)
            qw *= (1 - p[i]);
        for (int j = 0; j <= T; j++){
            v[j] = val;
            if (j - t[i] >= 0)
                val -= qw * (w[j - t[i]] + 1);
            val *= (1 - p[i]);
            val += p[i] * (w[j] + 1);
            if (j - t[i] + 1 >= 0)
                val += qw * (1 - p[i]) * (w[j - t[i] + 1] + 1);
        }
        // for (auto x : v)
        //  cerr << x << " ";
        // cerr << "\n";
        v.swap(w);
    }
    cout << setprecision(10) << fixed;
    cout << w[T] << "\n";

    return 0;
}