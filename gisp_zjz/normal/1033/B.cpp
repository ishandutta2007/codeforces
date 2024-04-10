#include<bits/stdc++.h>
#define maxn 1002

using namespace std;
typedef long long ll;
ll a,b,T;

bool is_prime(ll x){
    for (ll j=2;j*j<=x;j++) if (x%j==0) return false;
    return true;
}
int main(){
    cin >> T;
    while (T--){
        cin >> a >> b;
        if (a-b>1){puts("NO");continue;}
        b=b*2+1;
        if (is_prime(b)) puts("YES"); else puts("NO");
    }
}