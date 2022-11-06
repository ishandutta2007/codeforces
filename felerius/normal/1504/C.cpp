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

        int n; cin>>n;
        string s; cin>>s;
        int same = count(all(s), '1');
        if(same%2) {
            cout << "NO" << endl;
            continue;
        }
        same/=2;

        string a,b;

        int cnta=0, cntb=0;
        for(auto c : s) {
            if(c=='1') {
                if(same-->0) cnta++, cntb++, a.push_back('('), b.push_back('(');
                else cnta--, cntb--, a.push_back(')'), b.push_back(')');
            } else {
                if(cnta<cntb) cnta++, cntb--, a.push_back('('), b.push_back(')');
                else cnta--, cntb++, a.push_back(')'), b.push_back('(');
            }

            if(cnta<0 || cntb<0) {
                cout << "NO" << endl;
                goto nextl;
            }
        }

        cout << "YES" << endl;
        cout << a << endl;
        cout << b << endl;

        nextl: ;

    }

    return 0;
}