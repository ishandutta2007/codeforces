#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int main(){
    int n, k, odd = 0, even = 0, x, m;
    scanf("%d%d", &n, &k); m = k; k = n - k;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        odd += (x % 2 != 0);
        even += (x % 2 == 0);
    }

    int first = k - k / 2, second = k / 2;

    if (k & 1){ //try
        if (second >= odd) cout << "Daenerys" << endl;
        else if (second >= even && m % 2 == 0) cout << "Daenerys" << endl;
        else cout << "Stannis" << endl;
    }else{
        if (k == 0 && odd % 2 == 1) cout << "Stannis" << endl;
        else if (first >= even && m % 2 != 0) cout << "Stannis" << endl;
        else cout << "Daenerys" << endl;
    }
}