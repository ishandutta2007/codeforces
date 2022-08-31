#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> l(n), c(n);
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    map<int, int> M;
    M[0] = 0;
    for (int i = 0; i < n; i++){
        map<int, int> N;
        for (auto x : M){
            int y = __gcd(x.x, l[i]);
            if (N.count(y)){
                N[y] = min(N[y], x.y + c[i]);
            } else {
                N[y] = x.y + c[i];
            }
        }
        for (auto x : N){
            if (M.count(x.x)){
                M[x.x] = min(M[x.x], x.y);
            } else {
                M[x.x] = x.y;
            }
        }
    }
    if (M.count(1))
        cout << M[1] << "\n";
    else
        cout << "-1\n";

    return 0;
}