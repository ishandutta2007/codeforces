#include<bits/stdc++.h>
#define maxn 300050
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
struct pi{
    ll x,y;
    pi operator-(const pi &u){return (pi){x-u.x,y-u.y};}
    ll operator^(const pi &u){return x*u.y-y*u.x;}
}a[305];
bitset <305> f[305][305];
int n;
ll ans,w;

int main(){
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i].x >> a[i].y;
    ans=1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/60;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            for (int k=0;k<n;k++) if (k!=i&&k!=j){
                ll p=(a[i]-a[k])^(a[j]-a[k]);
                if (p>0) f[i][j][k]=1; else f[j][i][k]=1;
            }
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            for (int k=i+1;k<n;k++) if (j!=k){
                w=(f[i][j]&f[j][k]&f[k][i]).count();
                ans-=w*(n-4);
                ans+=w*(w-1);
            }
    cout << ans/2 << endl;
}