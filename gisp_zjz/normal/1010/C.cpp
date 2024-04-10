#include<bits/stdc++.h>
#define F first
#define S second
#define maxn 123456

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int a[maxn],n,k,r;

int main(){
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        a[i]%=k;
        if (a[i]==0) a[i]=k;
    }
    r=k;
    for (int i=0;i<n;i++) r=__gcd(r,a[i]);
    cout << k/r << endl;
    for (int i=0;i<k/r;i++) cout << i*r << ' ';cout << endl;
    return 0;
}