#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
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
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

char s[10][10] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char t[10];

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", t);
    for (int i = 0; i < 8; i++)
    if (n == strlen(s[i])){
        int flag = 0;
        for (int j = 0; j < n; j++)
        if (t[j] != '.' && t[j] != s[i][j]) flag = 1;
        if (!flag) cout << s[i] << endl;
    }
}