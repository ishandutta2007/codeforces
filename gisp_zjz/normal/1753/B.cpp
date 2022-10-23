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
int n,k,a[maxn];
void solve(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        int x; cin >> x;
        a[x]++;
    }
    for (int i=1;i<k;i++){
        a[i+1]+=a[i]/(i+1);
        a[i]%=(i+1);
        if (a[i]){puts("No");return;}
    }
    puts("Yes");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    while (_--) solve();
}