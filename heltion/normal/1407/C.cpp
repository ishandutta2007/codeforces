#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 10000 + 1;
int p[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int x = 1;
    for(int i = 2, a, b; i <= n; i += 1){
        cout << "? " << x << " " << i << endl;
        cin >> a;
        cout << "? " << i << " " << x << endl;
        cin >> b;
        if(a > b){
            p[x] = a;
            x = i;
        }
        else p[i] = b;
    }
    p[x] = n;
    cout << "! ";
    for(int i = 1; i <= n; i += 1) cout << p[i] << " ";
    return 0;
}