#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    bool rev = false;
    vector<bool> ans(n);
    for(int i=n-1;i>=0;--i) {
        if(s[i]=='a' && !rev) {
            rev = !rev;
            ans[i] = true;
        }
        else if(s[i]=='b' && rev) {
            ans[i] = true;
            rev = !rev;
        }
    }
    rep(i,0,n) {
        int x = ans[i]?1:0;
        cout<<x<<" ";
    }
    cout<<endl;
}