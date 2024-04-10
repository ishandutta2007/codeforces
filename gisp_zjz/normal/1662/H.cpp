#include<bits/stdc++.h>
using namespace std;
int _,n,m,a,b,c,d;
set<int> ans;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> m;
        for (int i=0;i<16;i++){
            a=c=n; b=d=m;
            if ((i>>0)&1) a--; else b--;
            if ((i>>1)&1) a--; else d--;
            if ((i>>2)&1) c--; else b--;
            if ((i>>3)&1) c--; else d--;
            int g=__gcd(__gcd(a,b),__gcd(c,d));
            for (int x=1;x*x<=g;x++) if (g%x==0){
                if (ans.find(x)==ans.end()) ans.insert(x);
                if (ans.find(g/x)==ans.end()) ans.insert(g/x);
            }
        }
        cout << ans.size();
        for (auto x:ans) cout << ' ' << x; cout << endl;
        ans.clear();
    }
}