#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    int x = -1, y = -1;
    for(int i = 0, a; i < n; i += 1){
        cin >> a;
        if(x == -1 and a % p) x = i;
    }
    
    for(int i = 0, b; i < m; i += 1){
        cin >> b;
        if(y == -1 and b % p) y = i;
    }
    cout << x + y;
    return 0;
}