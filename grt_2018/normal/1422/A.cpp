#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

int t,a,b,c;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        ll s = (ll)a + b + c;
        cout << s - 1 << "\n";
    }


}