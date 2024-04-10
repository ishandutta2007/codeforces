#include<bits/stdc++.h>
#define maxn 505050
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll n,m,a[maxn],u,v,cc;
set <pi> s;

int main(){
    cin >> n >> m;
    if (m==n*(n-1)/2) {puts("NO"); return 0;}
    while (m--){
        cin >> u >> v;
        if (u>v) swap(u,v);
        s.insert((pi){u,v});
    }
    bool flag=false;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (s.find((pi){i,j})==s.end()) {u=i; v=j; flag=true; break;}
        }
        if (flag) break;
    }
    puts("YES"); cc=2; a[u]=1; a[v]=2;
    for (int i=1;i<=n;i++) if (i!=u&&i!=v) a[i]=++cc;
    for (int i=1;i<=n;i++)  cout << a[i] << ' '; cout << endl; a[v]=1;
    for (int i=1;i<=n;i++)  cout << a[i] << ' '; cout << endl;
    return 0;
}