#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector< string > S(N);
        for(auto& s : S) {
            cin >> s;
            for(auto& c : s) c -= '0';
        }
        int ret = 0;
        vector< vector< int > > score(N, vector< int >(N));
        for(int i = 0; i < 4; i++) {
            auto X = S;
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    X[j][k] = S[N-1-k][j];
                }
            }
            S = X;
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    score[j][k] += X[j][k];
                }
            }
        }
        for(int i = 0; i < (N + 1) / 2; i++) {
            for(int j = 0; j < N / 2; j++) {
                ret += min(score[i][j], 4 - score[i][j]);
            }
        }
        cout << ret << endl;
    }
}