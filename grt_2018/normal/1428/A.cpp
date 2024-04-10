#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

pi ask(int x) {
    cout << "? " << x << endl;
    int a,b;
    cin >> a >> b;
    return {a,b};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        ll d = abs(x - a) + abs(y - b) + ((x != a && y != b) ? 2 : 0);
        cout << d << "\n";
    }


}