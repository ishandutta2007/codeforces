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
int n,m;
void solve(){  
    cin >> n >> m;
    if (m<n) {puts("No");return;}
    if (n%2==1){
        puts("Yes");
        for (int i=1;i<n;i++) printf("%d ",1);
        printf("%d\n",m-n+1);
    } else {
        if (m%2==1){puts("No");return;}
        puts("Yes");
        for (int i=1;i<=n-2;i++) printf("%d ",1);
        printf("%d %d\n",(m-n)/2+1,(m-n)/2+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}