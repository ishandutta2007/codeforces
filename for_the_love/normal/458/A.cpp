#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

char s[N], t[N];
int a[N], b[N];


DB Calc(int a){
    return a * sqrt(5) + a;
}

int cmp(DB a, DB b){
    if (fabs(a - b) < eps) return 0;
    if (a - b > eps) return 1;
    return -1;
}

int main(){

    scanf("%s", s);
    scanf("%s", t);
    int l1 = strlen(s), l2 = strlen(t), t1 = 0, t2 = 0;
    while (s[t1] == '0') t1++;
    while (t[t2] == '0') t2++;
    int n = 0, m = 0;
    for (int i = l1 - 1; i >= t1; i--) a[++n] = s[i] - '0';
    for (int i = l2 - 1; i >= t2; i--) b[++m] = t[i] - '0';

    for (int i = max(n, m); i >= 1; i--){
        if (i == 1){
            int t = cmp(Calc(a[i] + 2 * a[i - 1]), Calc(b[i] + 2 * b[i - 1]));
            if (t == -1) puts("<"); else if (t == 1) puts(">"); else puts("=");
            return 0;
        }
        if (a[i] == b[i]) continue;
        if (a[i] < b[i]){
            if (b[i] - a[i] - a[i - 1] > 0){
                puts("<");
                return 0;
            }
            b[i - 1] += b[i] - a[i];
            b[i - 2] += b[i] - a[i];
            b[i] -= b[i] - a[i];
        }else{
            if (a[i] - b[i] - b[i - 1] > 0){
                puts(">");
                return 0;
            }
            a[i - 1] += a[i] - b[i];
            a[i - 2] += a[i] - b[i];
            a[i] -= a[i] - b[i];
        }
    }
    puts("=");

}