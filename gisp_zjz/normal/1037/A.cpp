#include<bits/stdc++.h>
#define maxn 123456
#define M 1000000007

using namespace std;
typedef long long ll;
ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}
int n,ans,k;
int main(){
    cin >> n; k=0; ans=0;
    while (k<n) {
        k=k*2+1; ans++;
    }
    cout << ans << endl;
}