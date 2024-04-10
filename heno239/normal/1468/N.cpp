#include <iostream>
using namespace std;
using ll = long long;

bool solve(){
    ll c1, c2, c3;
    cin>>c1>>c2>>c3;
    ll a1,a2,a3,a4,a5;
    cin>>a1>>a2>>a3>>a4>>a5;
    if(c1<a1||c2<a2) return false;
    c1-=a1;
    c2-=a2;
    a4-=min(c1,a4);
    a5-=min(c2,a5);
    return a3+a4+a5<=c3;
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cout<<(solve()?"YES":"NO")<<endl;
    }
}