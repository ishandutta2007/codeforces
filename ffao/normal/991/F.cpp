#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>


using namespace std;


#include <cmath>


void re(long long& x);


void pr(const char *x);
void pr(std::string x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#include <array>


#include <sstream>


long long pow10[18];
set<long long> s[10];
map<long long, string> m;
stringstream ss;

void update(long long p, stringstream& ss) {
    string ts = ss.str(); 
    if (p < pow10[ts.size()]) return;
            
    auto it = m.find(p);
    if (it == m.end() || it->second.size() > ts.size()) {
        s[ts.size()].insert(p);
        if (it != m.end()) s[it->second.size()].erase(p);
        m[p] = ts;
    }
}

void ppow() {
    for (int i = 2; i*1ll*i <= 10000000000; i++) {
        for (long long p = i*1ll*i, k = 2; p <= 10000000000; p *= i, k++) {
            ss.str("");
            ss << i << '^' << k;
            update(p, ss);
        }
    }
}

void pmul() {
    for (int i = 3; i <= 7; i++) {
        for (long long x : s[i]) {
            for (int j = i; j <= 7-1-i; j++) {
                for (long long y : s[j]) {
                    if (x <= 10000000000/y) {
                        ss.str("");
                        ss << m[x] << '*' << m[y];
                        update(x*y, ss);
                    }
                }
            }

            string mx = m[x];
            int len_x = m[x].size();
            for (int j = 2; j <= pow10[7-1-len_x]; j++) {
                ss.str("");
                ss << m[x] << '*' << j;
                update(x*j, ss);
            }
        }
    }
}

void solve()
{
    pow10[0]=1; for (int i = 1; i <= 18; i++) pow10[i] = pow10[i-1]*10;
    ppow();
    pmul();

    long long n;
    re(n);
    ss.str("");
    ss << n;
    string ans = ss.str();

    for (auto &p : m) {
        if (p.first > n) break;
        else if (p.first == n) { ans = p.second; break; }
        
        long long d = n - p.first;

        string repd;
        ss.str(""); ss << d; repd = ss.str();
        auto it = m.find(d);
        if (it != m.end()) repd = it->second;

        string ts = p.second + '+' + repd;
        if (ts.size() < ans.size()) ans = ts;

        if (n % p.first == 0) d = n / p.first;
        ss.str(""); ss << d; repd = ss.str();
        it = m.find(d);
        if (it != m.end()) repd = it->second;

        ts = p.second + '*' + repd;
        if (ts.size() < ans.size()) ans = ts;
    }

    ps(ans);
}


int main() {


    solve();
}


 // and triples


void re(long long& x) { scanf("%lld", &x); }


void pr(const char *x) { printf("%s", x); }
void pr(std::string x) { printf("%s", x.c_str()); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}