#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int a[maxn];
struct F{
    int a, b, c;
};
void G(int x, int y, int z){
    //cout << x << " " << y << " " << z << "\n";
    int w = a[x] ^ a[y] ^ a[z];
    a[x] = a[y] = a[z] = w;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 1) cin >> a[i];
    vector<F> v;
    for(int i = 3; i <= n; i += 2){
        v.push_back({i, i - 1, i - 2});
        G(i, i - 1, i - 2);
    }
    for(int i = 1; i + 2 < n - (n % 2 == 0); i += 2){
        v.push_back({i, i + 1, n - (n % 2 == 0)});
        G(i, i + 1, n - (n % 2 == 0));
    }
    if(a[n] == a[n - 1]){
        cout << "YES\n";
        cout << v.size() << "\n";
        for(F f : v) cout << f.a << " " << f.b << " " << f.c << "\n";
    }
    else cout << "NO";
    return 0;
}