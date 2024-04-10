#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    char best='.';
    for(char c:s) {
        if(best=='.' || c<=best) {
            cout<<"Mike\n";
            best = c;
        }
        else cout <<"Ann\n";
    }
}