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

const int N = 50;
char a[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int aa, b, c, d;
    cin >> aa >> b >> c >> d;

    --aa;
    --b;

    cout << N << ' ' << N << endl;
    for (int i = 0; i < 25; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = 'A';
    for (int i = 25; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = 'B';
    for (int i = 1; i < 25; i += 2) {
        for (int j = 1; j < 50; j += 2) {
            if (b) {
                a[i][j] = 'B';
                --b;
            }   
            else if (c) {
                a[i][j] = 'C';
                --c;
            }   
            else if (d) {
                a[i][j] = 'D';
                --d;
            }   
        }   
    }   
    for (int i = 26; i < N; i += 2) {
        for (int j = 0; j < N; j += 2) {
            if (aa) {
                a[i][j] = 'A';
                --aa;
            }   
            else if (c) {
                a[i][j] = 'C';
                --c;
            }   
            else if (d) {
                a[i][j] = 'D';
                --d;
            }   
        }   
    }   
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << a[i][j];
        cout << endl;                
    }   
}