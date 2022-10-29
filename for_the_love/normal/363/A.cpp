//#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <cassert>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2222;
const int INF = 1e9;
const long long MOD = 1e9 + 7;

int main(){
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    if (!n){puts("O-|-OOOO"); return 0;}
    while (n){
        int x = n % 10;
        n /= 10;
        if (x == 0) puts("O-|-OOOO");
        if (x == 1) puts("O-|O-OOO");
        if (x == 2) puts("O-|OO-OO");
        if (x == 3) puts("O-|OOO-O");
        if (x == 4) puts("O-|OOOO-");
        if (x == 5) puts("-O|-OOOO");
        if (x == 6) puts("-O|O-OOO");
        if (x == 7) puts("-O|OO-OO");
        if (x == 8) puts("-O|OOO-O");
        if (x == 9) puts("-O|OOOO-");
    }
}