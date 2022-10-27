#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ld d;
        cin>>d;
        ld det = d*d - 4*d;
        if(det < 0){
            cout<<"N"<<endl;
        }else{
            cout<<"Y ";
            ld a = (d + sqrt(d*d - 4*d))/2;
            ld b = (d - sqrt(d*d - 4*d))/2;
            cout<<setprecision(30)<<a<<" "<<b<<endl;
        }
    }
}