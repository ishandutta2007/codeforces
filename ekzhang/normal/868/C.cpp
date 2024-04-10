#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 100013
int N, K;
bool in[16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    bool ans = 0;
    for (int i = 0; i < N; i++) {
        int x = 0;
        for (int j = 0; j < K; j++) {
            x <<= 1;
            int b; cin >> b; x |= b;
        }
        in[x] = true;
    }
    
    for (int x = 0; x < 16; x++) if (in[x]) {
        for (int y = 0; y < 16; y++) {
            if (in[y] && !(x & y)) {
                // yay two-problem test!
                ans = true;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}