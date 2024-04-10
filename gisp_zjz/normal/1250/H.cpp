#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=100005;
ll n,p1,p2;

int main(){
    cin >> n;
    for (ll i=2;i*i<=n;i++){
        if (n%i==0){
            while (n%i==0) n/=i;
            if (!p1) p1=i; else {puts("1");return 0;}
        }
    }
    if (n>1){
        if (!p1) p1=n; else {puts("1");return 0;}
    }
    if (p1) printf("%lld\n",p1); else puts("1");
    return 0;
}