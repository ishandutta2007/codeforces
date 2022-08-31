#include<bits/stdc++.h>
#define maxn 234005
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
ll n,k,r,t;
int main(){
    cin >> n >> k;
    if (k&1) r=(k+1)/2; else r=k/2+1;
    t=min(n-r+1,(k-1)/2);
    cout << max(0ll,t) << endl;
}