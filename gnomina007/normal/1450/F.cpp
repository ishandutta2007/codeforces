#include <random>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include <bitset>
#include<queue>
#include<ctime>
#include<unordered_map>

using namespace std;


using ll = long long;
using ull = unsigned long long;

using ld = long double;

const int mod = 998244353;
//const int mod = 1e9 + 7;

int sum(int a, int b) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }
    return c;
}

int dif(int a, int b) {
    int c = a - b;
    if (c < 0) {
        c += mod;
    }
    return c;
}

int mlt(int a, int b) {
    ll c = a * 1LL * b;
    return c % mod;
}

int ibit(int n, int i) {
    return ((n >> i) & 1);
}


void outp2(vector<vector<int>> &ou, string s = " ") {
    cerr << s << endl;
    for (int i = 0; i < ou.size(); i++) {
        for (int j = 0; j < ou[i].size(); j++) {
            cerr << ou[i][j] << ' ';
        }
        cerr << '\n';
    }
}

int bp(int x, int y) {
    if (y == 0) {
        return 1;
    }
    int a = 0;
    if (!(y % 2)) {
        a = bp(x, y / 2);
    }
    return (y % 2) ? mlt(bp(x, y - 1), x) : mlt(a, a);
}

int obr(int x) {
    return bp(x, mod - 2);
}

const int maxn = 2e5 + 2;
int fact[maxn], ofact[maxn];

void prec() {
    fact[0] = 1;
    ofact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = mlt(fact[i - 1], i);
    }
    //cerr << "sdsds" << endl;
    ofact[maxn - 1] = obr(fact[maxn - 1]);
    for (int i = maxn - 2; i > 0; i--) {
        ofact[i] = mlt(ofact[i + 1], i + 1);
    }
}

int c(int a, int b) {
    return ((a <= b) && (a >= 0)) ? mlt(fact[b], mlt(ofact[a], ofact[b - a])) : 0;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout) {
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++) {
        int n;
        cin >> n;
        vector<int> bords(n + 1), v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if (n == 1)
            cout << 0 << '\n';
        else {
            vector<int> inseg(n + 1);
            inseg[0] = 1;
            for (int i = 0; i < n - 1; i++)
                if (v[i] == v[i + 1])
                    inseg[i + 1] = 1;
            inseg[n] = 1;
            vector<int> vs(n + 1);
            for (int i = 0; i < n; i++) {
                if (inseg[i])
                    vs[v[i]]++;
                if (inseg[i + 1])
                    vs[v[i]]++;
            }
            int sum = 0, good = -1;
            for (int j = 1; j <= n; j++)
                sum += vs[j];
            for (int j = 1; j <= n; j++)
                if (vs[j] > sum / 2 + 1)
                    good = j;
            if (good == -1)
                cout << sum / 2 - 1 << '\n';
            else {
                int free = 0;
                for (int j = 0; j < n; j++) {
                    if (!inseg[j + 1])
                        if (v[j] != good && v[j + 1] != good)
                            free += 2;
                }
                int s1=sum+free;
                if(vs[good]<=s1/2+1)
                    cout<<vs[good]-2<<'\n';
                else
                    cout<<-1<<'\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto st = clock();

        ifstream fin("../input.txt");
        do
        {
            solve(fin);

            cout << "===" << endl;

            string str;
            while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
        } while (fin);

        cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
    solve();
#endif

    return 0;
}