#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y;
    cin >> x >> y;
    int n = x.size();
    for(int i = 0; i < n; i += 1)
        if(x[i] < y[i]){
            cout << "-1";
            return 0;
        }
    cout << y;
    return 0;
}