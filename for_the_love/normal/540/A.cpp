#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const int eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main(){
    int n;
    string s, t;
    int ans = 0;
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < n; i++){
        int a = s[i] - '0', b = t[i] - '0';
        ans += min(abs(b + 10 - a), min(abs(a - b), abs(a + 10 - b)));
    }
    cout << ans << endl;




}