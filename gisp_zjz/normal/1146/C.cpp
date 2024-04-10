#include<bits/stdc++.h>
#define maxn 300050
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int ans,T,n,x;
vector <int> a,b;

int main(){
    cin >> T;
    while (T--){
        cin >> n; ans=0;
        for (int i=0;i<7;i++){
            a.clear(); b.clear();
            for (int j=0;j<n;j++) if (j&(1<<i)) b.pb(j); else a.pb(j);
            if (a.size()==0||b.size()==0) continue;
            cout << a.size() << ' ' << b.size();
            for (auto x:a) cout << ' ' << x+1;
            for (auto x:b) cout << ' ' << x+1;
            puts("");
            fflush(stdout);
            cin >> x;
            ans=max(ans,x);
        }
        cout << -1 << ' ' << ans << endl;
        fflush(stdout);
    }
    return 0;
}