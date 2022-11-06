#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // bi = ai + a_i+1

    string s; cin>>s;
    int x=0,y=0;
    if(s.size()%2) cout << -1 << endl, exit(0);
    for(auto c : s) {
        if(c=='L') x++;
        if(c=='R') x--;
        if(c=='U') y++;
        if(c=='D') y--;
    }

    cout << (abs(x)+abs(y))/2 << endl;


    return 0;
}