#include<bits/stdc++.h>
using namespace std;
int _,n,k;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> k;
        int m=n-(n+1)/2+1;
        cout << k/m << endl;
    }
}