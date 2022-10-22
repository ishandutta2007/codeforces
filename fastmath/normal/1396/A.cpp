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
#define debug(x) std::cout << #x << ": " << x << '\n';

int gcd (int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
 
bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (n == 1) {
        cout << 1 << ' ' << 1 << endl;
        cout << -a[0] << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        cout << 1 << ' ' << 1 << endl;
        cout << 0 << endl;
        exit(0);
    }   
    
    const int INF = 1e9+7;

    vector <int> c1(n), c2(n);
    for (int i = 0; i < n - 1; ++i) {           
        int g;
        assert(find_any_solution(n - 1, n, -a[i], c1[i], c2[i], g));
        assert(abs(c1[i]) < INF);
        assert(abs(c2[i]) < INF);
    }   

    cout << 1 << ' ' << n - 1 << endl;
    for (int i = 0; i < n - 1; ++i) {
        cout << c1[i] * (n - 1) << ' ';
    }   
    cout << endl;

    cout << 1 << ' ' << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << c2[i] * n << ' ';
    }   
    cout << endl;

    cout << n << ' ' << n << endl;
    cout << -a.back() << endl;
}