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

const int C = 1000;

const int T = 1000 * 1000 * 1000;
const int INF = T * T;
int mult(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    if (a > INF/b+1)
        return INF+1;
    else
        return a * b;
}   

vector <int> prime = {181,313,97,163,229,661,17,337,401,223,19,449,317,571,379,431,61,479,137,233,107,11,677,373,433,691,607,523,269,5,409,593,487,79,683,311,617,601,397,239,673,7,349,563,193,271,211,307,149,67,3,251,359,463,151,347,557,241,613,197,37,167,443,283,257,73,491,503,461,109,421,173,127,521,103,569,139,419,101,59,353,439,331,389,227,29,31,631,659,541,113,277,199,281,599,641,43,383,647,499,263,179,577,23,131,587,653,41,89,71,619,2,53,293,457,13,157,547,467,83,367,643,191,47,509};
vector <vector <int> > quer;
vector <int> f;

vector <int> getp(int n) {
    vector <int> ans;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ans.app(i);
            n /= i;
        }   
    }   
    if (n > 1)
        ans.app(n);

    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());

    return ans;
}   

#ifdef HOME
int ANS, DV;
int get_div(int n) {
    map <int, int> d;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            ++d[i];
        }   
    }   
    if (n > 1)
        ++d[n];
    int ans = 1;
    for (auto e : d)
        ans *= e.s + 1;
    return ans;
}   
int get_ans(int x) {
    return __gcd(x, ANS);
}
bool check(int x) {
    return abs(x - DV) <= 7 || (x * 2 >= DV && DV * 2 >= x);
}   
#endif

int Q = 0;
int get(int n) {
    ++Q;
    if (Q > 22) {
        while (1) {}
    }

    int ans;
    #ifdef HOME
    ans = get_ans(n);            
    #else
    cout << "? " << n << endl;
    fflush(stdout);
    cin >> ans;
    #endif
    return ans;
}   

int get_max(int p) {
    int ans = 1;
    while (ans * p <= T)
        ans *= p;
    return ans;        
}   

void answer(int ans_div) {
    #ifdef HOME
    if (check(ans_div)) {
        /*
        cout << "OK" << endl;
        cout << "return " << ans_div << endl;
        cout << "answer " << DV << endl;
        */            
    }   
    else {
        cout << "WA" << endl;
        exit(0);
    }   
    #else
    cout << "! " << ans_div << endl;
    fflush(stdout);
    #endif
}

void solve() {
    Q = 0;

    #ifdef HOME
    cin >> ANS;                    
    DV = get_div(ANS);
    #endif

    vector <int> p;
    for (auto e : f) {
        for (auto pe : getp(get(e)))
            p.app(pe);
    }   

    map <int, int> d;

    int ptr = 0;
    int ans_div = 2;
    while (ptr < p.size()) {
        vector <int> who = {p[ptr]};
        int q = 1;
        q *= get_max(p[ptr]);
        ++ptr;
        if (ptr < p.size()) {
            q *= get_max(p[ptr]);
            who.app(p[ptr]);
            ++ptr;
        }

        int ans = get(q);
        for (int p : who) {
            int pw = 0;
            while (ans % p == 0) {
                ans /= p;
                ++pw;
            }   
            ans_div *= pw + 1;
        }   
    }   
    
    ans_div = max(ans_div, 8ll);
    answer(ans_div);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #endif

    int ptr = 0;
    for (int i = 0; i < 17; ++i) {
        int cur = 1;
        quer.app({});
        while (ptr < prime.size() && mult(cur,prime[ptr]) <= INF) {
            cur *= prime[ptr];
            quer.back().app(prime[ptr]);
            ++ptr;
        }
        f.app(cur);                             
    }   

    int t;
    cin >> t;  
    while (t--) {
        solve();
    }
}