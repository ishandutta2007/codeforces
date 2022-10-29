#include <map>
#include <set>
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
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    if (s[0] >= '5' && s[0] != '9'){
        s[0] = '9' - s[0] + '0';
    }
    for (int i = 1; i < s.size(); i++)
    if (s[i] >= '5') s[i] = '9' - s[i] + '0';
    cout << s << endl;
}