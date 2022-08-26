#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e5+10;
const int M=998244353;
int n;
ll ans,c[4];
int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        int x,y; cin >> x >> y;
        x/=2; y/=2;
        c[(x&1)*2+(y&1)]++;
    }
    ans=1ll*n*(n-1)*(n-2)/6;
    ans-=c[0]*c[1]*c[2];
    ans-=c[0]*c[1]*c[3];
    ans-=c[0]*c[2]*c[3];
    ans-=c[1]*c[2]*c[3];
    cout << ans << endl;
}