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
        string a,b; cin>>a>>b;
        auto acnt0 = count(all(a),'0');
        auto acnt1 = count(all(a),'1');
        auto bcnt0 = count(all(b),'0');

        if(acnt0 != bcnt0) {
            cout << "NO" << endl;
            continue;
        }

        bool inv = false;
        for(int i=n-1; i>=0; --i) {
            if(inv) a[i] = a[i]=='0' ? '1' : '0';
            if(a[i]!=b[i]) {
                if(i%2==0 || acnt0 != acnt1) {
                    cout << "NO" <<endl;
                    goto nextl;
                }
                inv^=1;
                a[i] = a[i]=='0' ? '1' : '0';
            };
            if(a[i]=='1') acnt1--;
            else acnt0--;
        }

        cout << "YES" << endl;

        nextl: ;
    }


    return 0;
}