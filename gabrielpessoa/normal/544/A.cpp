#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<string, string> ss;

const int SIZE  = 30;
const int MOD = 1E9 + 7;
const long double EPS = 1e-14;
const int INF = 0x3f3f3f3f;

bool letra[SIZE];
string s[SIZE];

int main() {
    int k;
    string q;
    cin >> k >> q;
    int p = 0;
    for(int i = 0; i < q.size(); i++) {
        if(p == k || letra[q[i] - 'a']) {
            s[p] += q[i];
        } else {
            s[++p] = q[i];
            letra[q[i] - 'a'] = true;
        }
    }
    if(p != k) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for(int i = 1; i <= k; i++) {
            cout << s[i] << endl;
        }
    }
    return 0;
}