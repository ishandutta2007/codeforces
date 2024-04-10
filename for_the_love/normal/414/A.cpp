#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
#define PB(x) push_back(x)

const int N = 2e7 + 5;
const int M = 1 << 21;
const int MOD = 1e9 + 7;

int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}

map <int, int> S;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 1){
        if (!k) puts("1"); else puts("-1");
        return 0;
    }
    if (k < n / 2){
        puts("-1");
        return 0;
    }
    int flag = n & 1;
    n /= 2;
    k -= n - 1;
    cout << k * 2 << " " << k * 3 << " ";
    S[k * 2] = S[k * 3] = 1;
    for (int i = 2; n > 1; i++)
    if (!S[i] && !S[i + 1]){
        n--;
        cout << i << " " << i + 1 << " ";
        i++;
    }
    if (flag) puts("1");
}