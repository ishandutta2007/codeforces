#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1e7+7;
bool p[N];
int some[N];

vector <int> dd[N/210];
ii mem[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
   
    for (int i = 2; i < N; ++i)
        p[i] = 1;
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            for (int j = 2 * i; j < N; j += i)
                p[j] = 0;
            for (int j = i; j < N; j += i)
                some[j] = i;
        }   
    }   

    for (int i = 2; i < N; ++i)
        for (int j = i; j < N; j += i)
            if (j % 210 == 0)
                dd[j/210].app(i);

    auto get = [](int n) {
        vector <int> ans;
        while (n > 1) {
            int p = some[n];
            ans.app(p);
            while (n % p == 0)
                n /= p;
        }   
        return ans;
    };   

    int n;
    cin >> n;
    vector <int> a(n), d1(n), d2(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (mem[a[i]].f) {
            tie(d1[i], d2[i]) = mem[a[i]];
        }   

        if (a[i] % 210 == 0) {

            vector <int> pd = get(a[i]);
            vector <int> &d = dd[a[i]/210];
            for (int x : pd) {
                for (int y : d) {
                    if (y > 1 && __gcd(x + y, a[i]) == 1) {
                        d1[i] = x;
                        d2[i] = y;
                        break;
                    }   
                }   
            }   
            mem[a[i]] = mp(d1[i], d2[i]);

            continue;
        }   

        d1[i] = d2[i] = -1;

        vector <int> d = get(a[i]);

        for (int p1 : d) {
            for (int p2 : d) {
                if (__gcd(p1 + p2, a[i]) == 1) {
                    d1[i] = p1;
                    d2[i] = p2;
                    break;
                }   
            }   
        }   
        mem[a[i]] = mp(d1[i], d2[i]);


    }
    
    for (int i = 0; i < n; ++i)
        cout << d1[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; ++i)
        cout << d2[i] << ' ';
    cout << endl;

    #ifdef HOME
    cout << Time << endl;
    #endif
}