#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1000000007;
ll n,m,r,c,k,A,B,C,D;
ll pow_(ll x,ll y){
    ll ret=1;
    while (y){
        if (y&1) ret=ret*x%M;
        x=x*x%M; y>>=1;
    }
    return ret;
}
int main(){
    cin >> n >> m >> k >> r >> c;
    cin >> A >> B >> C >> D;
    if (A==C&&B==D) cout << pow_(k,n*m) << endl;
    else cout << pow_(k,n*m-r*c) << endl;
}