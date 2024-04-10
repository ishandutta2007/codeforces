#include<bits/stdc++.h>
using namespace std;

int solve() {
    long long n, m;
    cin >> n >> m;

    long long t = n / m;

    long long sum=0, add=0;
    for(int i=0; i <= 9; i++) {
        sum += (m * i)%10;
        if(i == t % 10) add = sum;
    }

    cout << t/10 * sum + add << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;

    while(q--) {
        solve();
    }
}