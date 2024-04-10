#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

const int nax = 500 * 1000 + 10;
int n;
string s;
int cnt[nax];
ll ans = 0;
ll sum = 0;
int pw = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    int L = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
            L++;
            pw++;
            pw += cnt[L - 1];
        } else {
            int ile = 0;
            for(int j = 0; j < L; ++j) {
                ile += cnt[j];
                cnt[j] = 0;
            }
            cnt[L] += ile;
            for(int j = 0; j <= L; ++j) {
                cnt[j]++;
            }
            pw = 0;
            L = 0;
        }
        sum += pw;
        //cout << L << " " << sum << "\n";
        ans += sum;
    }
    cout << ans;


}