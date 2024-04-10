#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
 
int t;
string s;
const int nax = 500 * 1000 + 10;
int p[nax];
 
 
int main() {_
	cin >> t;
	while(t--){
        cin >> s;
        multiset<int>S = {};
        for(int i = 1; i <= (int)s.size(); ++i) {
            p[i] = p[i - 1] + (s[i - 1] == '1' ? 1 : -1);
            if(s[i - 1] == '1') S.insert(p[i]);
        }
        int cur = 0;
        string ans = "";
        for(int i = 1; i <= (int)s.size(); ++i) {
            auto it = S.find(cur + 1);
            if(it == S.end()) {
                cur--;
                ans += "0";
            } else {
                if(S.count(cur)) {
                    cur--;
                    ans += "0";
                } else {
                    cur++;
                    ans += "1";
                    S.erase(it);
                }
            }
        }
        cout << ans << "\n";
	}
}