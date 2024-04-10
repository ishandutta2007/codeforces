#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

LL pw(LL a, LL b, LL base){
    LL res = 1;
    while (b){
        if (b & 1)
            res = (res * a) % base;
        b >>= 1;
        a = (a * a) % base;
    }
    return res;
}

int main(){

    int n;
    cin >> n;
    if (n == 1){
        cout << "YES\n1\n";
        return 0;
    }
    if (n == 2){
        cout << "YES\n1\n2\n";
        return 0;
    }
    if (n == 4){
        cout << "YES\n1\n3\n2\n4\n";
        return 0;
    }
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            cout << "NO\n";
            return 0;
        }
    }
    vector<int> p;
    for (int i = 1; i < n - 1; i++){
        if ((n - 1) % i == 0)
            p.pb(i);
    }
    int d = 2;
    while (1){
        bool ok = true;
        for (auto x : p){
            if (pw(d, x, n) == 1){
                ok = false;
                break;
            }
        }
        if (ok) break; else d++;
    }
    cout << "YES\n";
    int x = 0;
    for (int i = 0; i + i < n - 2; i++){
        int y = n - 1 - i, z = i + 1;
        if (i == 0) y = 0;
        int Y = y - x, Z = z - y;
        x = z;
        if (Y < 0) Y += n - 1;
        if (Z < 0) Z += n - 1;
        cout << pw(d, Y, n) << "\n" << pw(d, Z, n) << "\n";
    }
    cout << n << "\n";

    return 0;
}