#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 2020;
const int N = 1e5 + 13;
const int B = 150;
const int P = 11000;

/*
*/

int n1, x1;
set<int> st;
int cnt = 0;

void init(int n, int x) {
    n1 = n;
    x1 = x;
    cnt = 0;
    for(int i = 1; i <= n; i++)
        st.insert(i);
}

int get(int d) {
    cnt++;
    int res = 0;
    for(int i = d; i <= n1; i += d)
        res += st.count(i);
    return res;
}

int del(int d) {
    cnt++;
    int res = 0;
    for(int i = d; i <= n1; i += d) {
        res += st.count(i);
        if(i != x1)
            st.erase(i);
    }

    return res;
}

int getA(int a) {
//    return get(a);
    cout << "A " << a << endl;
    int res;
    cin >> res;
    return res;
}

int getB(int a) {
//    return del(a);
    cout << "B " << a << endl;
    int res;
    cin >> res;
    return res;
}

void getC(int a) {
    cout << "C " << a << endl;
}

int is[N];
vector<int> p[P / B];

int main() {
//    init(100000, 99991);

    int n = 100000;
    cin >> n;

    int cur = 0;
    for(int i = 2; i <= n; i++) {
        if(is[i] == 0) {
            p[cur].push_back(i);
            if(p[cur].size() == B)
                cur++;

            if(i * 1ll * i <= n) {
                for(int j = i * i; j <= n; j += i)
                    is[j] = i;
            }
        }
    }

    vector<int> q;
    int m = n;
    for(int i = 0; i <= cur; i++) {
        int res = 0;
        for(auto a : p[i]) {
            res += getB(a);
        }

        int m1 = getA(1);
        if(m - res != m1) {
            for(auto a : p[i]) {
                if(getA(a)) {
                    q.push_back(a);
                }
            }
        }

        m = m1;
    }

    int x = 1;
    for(auto a : q) {
        int pw = a;
//        cout << pw << endl;
        for(int i = 0; ; i++) {
            if(pw * 1ll * a <= n && getA(pw * a))
                pw *= a;
            else
                break;
        }
        x *= pw;
    }

//    cout << cnt << endl;
    getC(x);
}