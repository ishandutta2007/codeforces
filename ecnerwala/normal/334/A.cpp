#include<iostream>

using namespace std;

int main() {
    int N; cin >> N;
    int low = 1;
    int high = N * N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N / 2; j++) {
            cout << low++ << ' ' << high-- << ' ';
        }
        cout << '\n';
    }
    return 0;
}