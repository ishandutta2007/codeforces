#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, T; cin >> N >> T;
    vector<double> dp(T + 1, 0), next(T + 1);
    dp[0] = 1.0;

    double answer = 0;
    for (int i = 0; i < N; ++i) {
        double p; int t; cin >> p >> t;
        p /= 100;

        double remove = 1;
        for (int i = 1; i < t; ++i)
            remove *= (1 - p);
        double add = remove * (1 - p);

        for (int j = 0; j <= T; ++j) {
            next[j] = 0;
            if (j == 0)
                continue;
            double aux = next[j - 1];
            if (j - t - 1 >= 0)
                aux -= dp[j - t - 1] * remove;
            aux *= (1 - p);
            if (j - t >= 0)
                aux += dp[j - t] * add;
            aux += dp[j - 1] * p;
            next[j] = aux;
            answer += aux;
        }
        swap(dp, next);
    }

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(9);
    cout << answer << "\n";
}