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

char s[1005][1005];

int main(){
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m - 1; j++){
        vector <char> vec;
        vec.push_back(s[i][j]);
        vec.push_back(s[i + 1][j]);
        vec.push_back(s[i][j + 1]);
        vec.push_back(s[i + 1][j + 1]);
        sort(vec.begin(), vec.end());
        if (vec[0] == 'a' && vec[1] == 'c' && vec[2] == 'e' && vec[3] == 'f') ans++;
    }
    printf("%d\n", ans);

}