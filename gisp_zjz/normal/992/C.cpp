#include<bits/stdc++.h>
#define maxn 502030
#define M 1000000007

using namespace std;
typedef long long ll;
ll n,k;

ll pow_(ll x,ll y){
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%M;
        x=x*x%M;
        y>>=1;
    }
    return rt;
}

int main(){
    cin >> n >> k;
    if (n==0){
        cout << 0 << endl;
        return 0;
    }
    n=(n*2-1+M)%M;
    n=pow_(2ll,k)*n%M;
    cout << (n+1)%M << endl;
}