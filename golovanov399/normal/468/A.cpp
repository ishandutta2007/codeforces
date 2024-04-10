#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

    int n;
    cin >> n;
    if (n >= 6){
        cout << "YES\n2 * 3 = 6\n6 * 4 = 24\n1 + 5 = 6\n6 - 6 = 0\n";
        for (int i = 7; i <= n; i++){
            cout << i << " * 0 = 0\n";
        }
        cout << "0 + 24 = 24\n";
    } else
    if (n == 5){
        cout << "YES\n5 * 4 = 20\n3 - 1 = 2\n2 * 2 = 4\n20 + 4 = 24\n";
    } else
    if (n == 4){
        cout << "YES\n1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}