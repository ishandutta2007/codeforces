#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int A[MAXN];
int X, Y;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> X >> Y;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        bool good = true;
        for (int j = max(i-X,0); j <= min(i+Y,N-1); j++) {
            if (i == j) continue;
            if (A[j] <= A[i]) good = false;
        }
        if (good) { cout << i+1 << '\n'; exit(0); }
    }
}