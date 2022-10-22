#include<bits/stdc++.h>
using namespace std;

#define int long long

void one() {
    cout << "sjfnb\n";
    exit(0);
}   

void two() {
    cout << "cslnb\n";
    exit(0);
}   

const int N = 1e5 + 7;

int a[N];
int get(int n) {
    return n * (n + 1) / 2;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int c = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    for (int i = 0; i + 1 < n; ++i) {
        c += a[i] == a[i + 1];            
    }   
    if (c > 1) two();

    if (c == 1) {
        int x = -1;
        for (int i = 0; i + 1 < n; ++i) {   
            if (a[i] == a[i + 1]) {
                x = a[i];
                break;
            }                   
        }
        if (x == 0) {
            two();
        }   
        for (int i = 0; i < n; ++i) {
            if (a[i] == x - 1) {
                two();
            }   
        }   
    }   

    int h = sum - get(n - 1);    
    if (h & 1) one();
    else two();
}