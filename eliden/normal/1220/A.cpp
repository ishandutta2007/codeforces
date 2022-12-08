#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zeros =0, ones = 0;
    for(char c:s){
        if(c=='z') ++zeros;
        if(c=='n') ++ones;
    }
    rep(i,0,ones) cout << "1 ";
    rep(i,0,zeros) cout << "0 ";
    cout<<endl;
}