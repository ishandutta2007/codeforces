#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0,d[1005],c[1005],cnt,n;
int qry(int x){
    cout << "? " << x << endl;
    fflush(stdout);
    int ret; cin >> ret;
    return ret;
}
void solve(){
    cin >> n; 
    for (int i=1;i<=n;i++) cin >> d[i];
    for (int i=1;i<=n;i++) c[i]=0; cnt=0;
    while (1){
        int p=-1;
        for (int i=1;i<=n;i++) if (!c[i]){
            if (p==-1||d[i]>d[p]) p=i;
        }
        if (p==-1) break;
        vi tmp(0); tmp.pb(p);
        for (int i=1;i<=d[p];i++){
            int x=qry(p);
            if (!c[x]) tmp.pb(x);
            else {
                for (auto y:tmp) c[y]=c[x];
                tmp.clear();
                break;
            }
        }
        if (tmp.size()){
            ++cnt;
            for (auto x:tmp) c[x]=cnt;
        }
    }
    cout << "!";
    for (int i=1;i<=n;i++) cout << " " << c[i];
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}