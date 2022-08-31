#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define float long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int main(){

    // freopen("aplusb.in", "r", stdin);
    // freopen("aplusb.out", "w", stdout);
    
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++){
        cout << i + 1 << " ";
    }
    for (int i = 0; i <= b; i++){
        cout << a + b + 1 - i << " ";
    }
    cout << "\n";

    return 0;
}