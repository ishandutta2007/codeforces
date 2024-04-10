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
int f[105][105][2][2];
int go(int x,int y,int p,int s){
    if (f[x][y][p][s]!=-1){
        return f[x][y][p][s];
    }
    if (x+y==0) return (s==0);
    int &ret=f[x][y][p][s];
    if (!p){
        ret=0;
        if (x>0) ret|=go(x-1,y,1-p,s);
        if (y>0) ret|=go(x,y-1,1-p,1-s);
    } else {
        ret=1;
        if (x>0) ret&=go(x-1,y,1-p,s);
        if (y>0) ret&=go(x,y-1,1-p,s);
    }
    return ret;
}
void solve(){
    int n; cin >> n;
    int s=0,t=0;
    for (int i=0;i<n;i++){
        int x; cin >> x;
        if (x&1) t++; else s++;
    }
    memset(f,-1,sizeof(f));
    if (go(s,t,0,0)) puts("Alice"); else puts("Bob");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}