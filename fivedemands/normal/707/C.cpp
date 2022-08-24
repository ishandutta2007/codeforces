#include<iostream>
typedef long long ll;
using namespace std;
int main(){
    ll n;
    cin >> n;
    if(n==1 || n==2){ cout << -1 << endl;
    return 0;}
    ll ans1,ans2=ans1=1;
    while(n%2==0){
        n/=2;
        ans1*=2;
        ans2*=2;
    }
    if(n==1){
        ans1/=4;
        ans2/=4;
        ans1*=3;
        ans2*=5;
    }
    else{
        ans1*=n*n/2;
        ans2*=n*n/2+1;
    }
    cout << ans1 << ' ' << ans2 << endl;
}