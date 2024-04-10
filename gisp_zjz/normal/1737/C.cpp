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
int kase=0;
int n,x[3],y[3],xx,yy;
bool f[2][2];
void solve(){
    cin >> n;
    for (int i=0;i<3;i++) cin >> x[i] >> y[i];
    cin >> xx >> yy;
    memset(f,0,sizeof(f));
    for (int i=0;i<3;i++) f[x[i]%2][y[i]%2]=1;
    for (int i=0;i<3;i++) if (!f[(x[i]+1)%2][(y[i]+1)%2]){
        if ((x[i]==1||x[i]==n)&&(y[i]==1||y[i]==n)){
            if (xx==x[i]||yy==y[i]) cout << "YES" << endl; 
            else cout << "NO" << endl;
            return;
        }
    }
    if (f[xx%2][yy%2]) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}