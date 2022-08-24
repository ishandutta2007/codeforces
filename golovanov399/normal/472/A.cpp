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

int main(){

    int n;
    cin >> n;
    if (n % 2 == 0){
        cout << 4 << " " << n - 4 << "\n";
    } else {
        cout << 9 << " " << n - 9 << "\n";
    }

    return 0;
}