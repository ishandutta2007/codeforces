#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

bool prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return 0;
    }   
    return 1;
}   

bool powerof2(int n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "FastestFinger" << endl;
        }   
        else if (n == 2) {
            cout << "Ashishgup" << endl;
        }   
        else if (powerof2(n)) {
            cout << "FastestFinger" << endl;
        }   
        else if (n % 4 == 0) {
            cout << "Ashishgup" << endl;
        }   
        else if (n & 1) {
            cout << "Ashishgup" << endl;
        }   
        else if (prime(n/2)) {
            cout << "FastestFinger" << endl;
        }   
        else {
            cout << "Ashishgup" << endl;
        }   
    }   

}