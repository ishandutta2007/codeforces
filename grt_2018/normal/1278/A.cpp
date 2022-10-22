#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t;
string s,h;

int main() {_
    cin>>t;
    while(t--) {
        cin>>s>>h;
        int m = (int)s.size();
        sort(s.begin(),s.end());
        bool ok = 0;
        for(int i=0; i+m<=(int)h.size(); i++) {
            string tmp = "";
            for(int j=i; j<i+m; j++) tmp+=h[j];
            sort(tmp.begin(),tmp.end());
            if(tmp==s) ok=1;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }




}