#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<bool>S = {};
        for(char c : s) {
            if(c == 'A') {
                S.PB(1);
            } else {
                if((int)S.size() == 0) {
                    S.PB(0);
                } else {
                    S.pop_back();
                }
            }
        }
        cout << (int)S.size() << "\n";
    }


}