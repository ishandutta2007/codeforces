#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
 
int n;
vector <int> sam[3];
const int N = 507;
int a[N][N];
 
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
 
    sam[0] = {0, 1, 3};
    sam[1] = {4, 2, 7}; 
    sam[2] = {8, 5, 6};
 
    cin >> n;
    if (n <= 2) {
        cout << -1 << endl;
        exit(0);
    }   
  
    int ptr = 1;
    int up = n - 1, r = n - 1;
    for (int len = n; len > 3; --len) {
        if (len & 1) {
            for (int i = 0; i < len; ++i)
                a[up][i] = ptr++;
            for (int i = len - 2; i >= 0; --i)
                a[i][r] = ptr++;
        }   
        else {
            for (int i = 0; i < len; ++i)
                a[i][r] = ptr++;
            for (int i = len - 2; i >= 0; --i)
                a[up][i] = ptr++;
        }   
        --up; --r;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[i][j] = sam[i][j] + ptr;
        }   
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }   
        cout << endl;
    }   
}