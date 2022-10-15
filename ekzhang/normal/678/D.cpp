#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;

#define MAXLG 62
#define MOD 1000000007LL
LL A, B, N, X;
LL e[MAXLG][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    
    cin >> A >> B >> N >> X;
    e[0][0] = A;
    e[0][1] = B;
    // [[A, B], [0, 1]] ** 2 = [[A^2, AB + B], [0, 1]]
    for (int i = 1; i < MAXLG; i++) {
        e[i][0] = (e[i - 1][0] * e[i - 1][0]) % MOD;
        e[i][1] = ((e[i - 1][0] + 1) * e[i - 1][1]) % MOD;
    }
    LL a = 1;
    LL b = 0;
    for (int i = MAXLG - 1; i >= 0; i--) {
        LL x = 1LL << i;
        if (x <= N) {
            N -= x;
            LL ap = a * e[i][0];
            LL bp = a * e[i][1] + b;
            a = ap % MOD;
            b = bp % MOD;
        }
    }
    cout << (a * X + b) % MOD << endl;
}