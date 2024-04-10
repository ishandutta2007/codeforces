#include<bits/stdc++.h>
#define maxn 123456

using namespace std;
typedef long long ll;
ll n,a[maxn],d,ans;
set <ll> s;

void check(ll x){
    if (s.find(x)!=s.end()) return;
    s.insert(x);
    for (int i=0;i<n;i++) if (abs(a[i]-x)<d) return;
    ans++;
}

int main(){
    cin >> n >> d;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++){
        check(a[i]+d); check(a[i]-d);
    }
    cout << ans << endl;
}