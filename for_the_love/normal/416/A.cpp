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


typedef double DB;
typedef long long LL;
const int N = 1005;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const double pi = acos(-1.0);

string s, t;
int main(){
    int n, x;
    scanf("%d", &n);
    int l = -INF, r = INF;
    for (int i = 0; i < n; i++){
        cin >> s >> x >> t;
        if (t == "N"){
            if (s == ">=") s = "<";
            else if (s == "<=") s = ">";
            else if (s == ">") s = "<=";
            else s = ">=";
        }
        if (s == ">=") x--;
        else if (s == "<=") x++;
        if (s[0] == '>'){
            if (r <= x){
                puts("Impossible");
                return 0;
            }
            l = max(l, x + 1);
        }else{
            if (l >= x){
                puts("Impossible");
                return 0;
            }
            r = min(r, x - 1);
        }
    }
    printf("%d\n", l);
}