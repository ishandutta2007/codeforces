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

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)


const int N = 209;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-6;

char s[N], t[N];
int main(){
    int ans = 0;
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i += 2){
        if (s[i] == '8' && t[i] == '(') ans--;
        else if (s[i] == '8' && t[i] == '[') ans++;
        else if (s[i] == '(' && t[i] == '8') ans++;
        else if (s[i] == '[' && t[i] == '8') ans--;
        else if (s[i] == '(' && t[i] == '[') ans--;
        else if (s[i] == '[' && t[i] == '(') ans++;
    }
    if (!ans) puts("TIE");
    else if (ans < 0) puts("TEAM 2 WINS");
    else puts("TEAM 1 WINS");
}