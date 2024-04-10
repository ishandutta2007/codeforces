#include <bits/stdc++.h>
using namespace std;

int A[5005], B[5005];

int N, X;

void run() {
    cin >> N >> X;
    for(int i = N; i; i--) cin >> A[i];
    
    for(int l = N; l; l--) {
        int s = 0;
        for(int i = l; i; i--) s += A[i];
        int mx = s;
        for(int i = l+1; i <= N; i++) {
            s += A[i] - A[i-l];
            if(mx < s) mx = s;
        }
        B[l] = mx;
    }
    
    for(int k = 0; k <= N; k++) {
        int mx = 0;
        for(int i = k; i; i--) {
            int t = B[i] + i*X;
            if(mx < t) mx = t;
        }
        for(int i = k+1; i <= N; i++) {
            int t = B[i] + k*X;
            if(mx < t) mx = t;
        }
        cout << mx << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    while(T--) run();
    
    return 0;
}