#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> D(N), S(N);
    for (int i = 0; i < N; ++i)
        cin >> D[i];
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    
    int maxt = 0;
    int answer = 0;
    int fuel = 0;
    for (int i = 0; i < N; ++i) {
        maxt = max(maxt, S[i]);
        fuel += S[i];
        while (fuel < D[i]) {
            fuel += maxt;
            answer += K;
        }
        fuel -= D[i];
        answer += D[i];
    }

    cout << answer;
}