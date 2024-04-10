#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int t, a, b;
    for(cin >> t; t; t -= 1){
        cin >> a >> b;
        if(a > b) swap(a, b);
        cout << (a * 2 <= b ? a : (a + b) / 3) << "\n";
    }
}