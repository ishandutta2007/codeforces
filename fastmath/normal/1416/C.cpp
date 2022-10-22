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

struct Node {

int cnt;
Node *to[2];

Node() {
    cnt = 0;
    for (int i = 0; i < 2; ++i) 
        to[i] = NULL;
}

} *root;  

const int LG = 30;
int sh[LG][2];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    root = new Node();

    auto get_cnt = [&] (Node *t) {
        if (!t)
            return 0ll;
        else
            return t->cnt;        
    };  

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        Node *t = root;
        t->cnt++;
        for (int bit = LG - 1; bit >= 0; --bit) {
            int x = ((a[i] >> bit) & 1);
            if (!t->to[x]) {
                t->to[x] = new Node();
            }   
            sh[bit][x] += get_cnt(t->to[x^1]);
            t = t->to[x];
            t->cnt++;
        }   
    }   

    int inv = 0, x = 0;
    for (int bit = 0; bit < LG; ++bit) {
        if (sh[bit][0] <= sh[bit][1]) {
            inv += sh[bit][0];
        }   
        else {
            inv += sh[bit][1];
            x += 1ll << bit;
        }   
    }   

    cout << inv << ' ' << x << endl;
}