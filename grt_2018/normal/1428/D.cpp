#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

const int nax = 100 * 1000 + 10;
int n;
int a[nax];
vector<pi>ans;
vi three, two, one;
int odp[nax];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int last = n;
    for(int i = n; i >= 1; --i) {
        if(a[i] == 0) continue;
        if(a[i] == 1) {
            ans.PB({last, i});
            one.PB(i);
            odp[i] = last;
            last--;
        } else if(a[i] == 2) {
            if((int)one.size() == 0) {
                cout << "-1";
                return 0;
            }
            ans.PB({odp[one.back()], i});
            one.pop_back();
            two.PB(i);
        } else if(a[i] == 3) {
            if((int)three.size() > 0) {
                ans.PB({last, i});
                ans.PB({last, three.back()});
                three.pop_back();
                last--;
            } else if((int)two.size() > 0) {
                ans.PB({last, i});
                ans.PB({last, two.back()});
                two.pop_back();
                last--;
            } else if((int)one.size() > 0) {
                ans.PB({last, i});
                ans.PB({last, one.back()});
                one.pop_back();
                last--;
            } else {
                cout << "-1";
                return 0;
            }
            three.PB(i);
        }
    }
    cout << (int)ans.size() << "\n";
    for(auto x : ans) {
        cout << x.ST << " " << x.ND << "\n";
    }


}