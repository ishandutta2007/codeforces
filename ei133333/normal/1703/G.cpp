#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
constexpr static int64 inf = (1LL << 61) - 1;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        vector< int > A(N);
        for(auto& a : A) cin >> a;
        vector< int64 > dp1(32, -inf);
        dp1[0] = 0;
        for(int i = 0; i < N; i++) {
            vector< int64 > dp2(32, -inf);
            int p = A[i];
            for(int j = 0; j < 32; j++) {
                dp2[j] = max(dp2[j], dp1[j] + p - K);
                p /= 2;
            }
            p = A[i];
            for(int j = 1; j < 32; j++) {
                p /= 2;
                dp2[j] = max(dp2[j], dp1[j - 1] + p);
            }
            dp2[31] = max(dp2[31], dp1[31]);
            dp1 = dp2;
        }
        cout << *max_element(dp1.begin(), dp1.end()) << endl;
    }
}