#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
const int MAXX = 1e9;
void solve(){
    int n;
    cin>>n;
    //A..................A....A.B..B...........
    auto query = [&](int x,int y){
        cout<<x<<" "<<y<<endl;
        string color;
        cin>>color;
        return color;
    };
    if(n==1){
        query(1,1);
        cout<<"2 2 2 0\n";
        return;
    }
    string color1 = query(0, 1);
    string color2 = query(MAXX/2, 1);
    ll mn = -1, mx = -1;
    if(color1==color2){
        mn = MAXX/2;
        mx = MAXX;
    }
    else{
        mn = 0;
        mx = MAXX/2;
    }
    for(int i=2;i<n;i++){
        int mid = mn + mx;
        mid/=2;
        if(color1 == query(mid, 1)){
            mn = mid;
        }
        else{
            mx = mid;
        }
    }
    //................ Y.....................
    //...............W B.....................
    //...............X ......................
    cout<<mn<<" 0 "<<mx<<" 2\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    solve();
}