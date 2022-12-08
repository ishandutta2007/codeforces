#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n;
        cin>>n;
        if(n==1) cout<<"-1\n";
        else {
            int twos= n-1;
            if(twos%3==0) --twos;
            rep(i,0,twos) cout<<"2";
            rep(i,twos,n) cout<<"3";
            cout<<"\n";
        }
    }
}