#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--) {

        string s; cin>>s;
        if(count(all(s),'a')==size(s)) {
            cout << "NO" << endl;
        } else {
            auto b = s;
            reverse(all(b));
            cout << "YES" << endl;
            if(s+'a' != 'a'+b) cout << s+'a' << endl;
            else cout << 'a'+s << endl;
        }

    }


    return 0;
}