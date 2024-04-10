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

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    n = min(n, m);
    if (n & 1) puts("Akshat"); else puts("Malvika");
}