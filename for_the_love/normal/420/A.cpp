#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 50 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;



bool C(char ch){
    if (ch == 'A' || ch == 'H' || ch == 'I' || ch == 'M' || ch == 'O' || ch == 'T' || ch == 'U' || ch == 'V' || ch == 'W' || ch == 'X' || ch == 'Y') return 1;
    return 0;
}


int main(){
    string s;
    cin >> s;
    int n = s.size(), flag = 0;
    for (int i = 0; i < n; i++)
    if (s[i] != s[n - i - 1] || !C(s[i])) flag = 1;
    if (flag) puts("NO"); else puts("YES");
}