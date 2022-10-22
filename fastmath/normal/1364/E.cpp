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
vector <int> per;
int quer;
int get(int i, int j) {
    ++quer;
    if (quer > 4269) {
        cout << "limit" << endl;
        exit(1);
    }   

    cout << "? " << i + 1 << ' ' << j + 1 << endl;

    #ifdef HOME
    return per[i] | per[j];
    #else
    fflush(stdout);
    int ans; cin >> ans;
    return ans;
    #endif
}   
mt19937 rnd(2007);
vector <int> solve(int n) {
    quer = 0;

    int a = 0, b = 1;
    int x = get(0, 1);
    for (int i = 2; i < n; ++i) {
        int y = get(b, i);
        if (x < y) {

        }
        else if (x == y) {
            b = i;
            x = get(a, i);
        }   
        else {
            a = i;
            x = y;
        }   

        #ifdef HOME
        //cout << "add " << i + 1 << endl;
        //cout << "a,b : " << a + 1 << ' ' << b + 1 << endl;
        #endif
    }   

    int num = -1;
    while (1) {
        int i = rnd() % n;
        if (i == a || i == b)
            continue;
        int x = get(a, i), y = get(b, i);
        if (x < y) {
            num = a;
            break;
        }   
        if (x > y) {
            num = b;
            break;
        }   
    }   

    #ifdef HOME
    //cout << "num : " << num + 1 << endl;
    #endif

    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        if (i == num)
            ans.app(0);
        else
            ans.app(get(num, i));
    }   
    
    return ans;
}   
signed main() {
    #ifdef HOME
    const int T = 10000;
    const int N = 10;
    for (int t = 0; t < T; ++t) {
        quer = 0;
        int n = 2048;

        per.clear();
        for (int i = 0; i < n; ++i)
            per.app(i);
        shuffle(all(per), rnd);

        #ifdef HOME
        cout << "start test" << endl;
        #endif

        auto res = solve(n);
        if (per != res) {
            cout << "WA" << endl;
            
            cout << n << endl;
            for (auto e : per)
                cout << e << ' ';
            cout << endl;
            
            exit(0);
        }   
    }
    #else
    int n;
    cin >> n;
    vector <int> ans = solve(n);
    cout << "! ";
    for (auto e : ans)
        cout << e << ' ';
    cout << endl;
    #endif
}