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


map <pair<int, PI>, int> S;

int l[6000005];
void Calc(string s){
    for (int i = 0; i < s.size(); i++){
        l[i + 1] = (l[i] * 71 + s[i]) % MOD;
    }
    int t = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--){
        int tmp = 0;
        if (s[i] == 'a'){
            tmp = 6;
        }else if (s[i] == 'b'){
            tmp = 5;
        }else if (s[i] == 'c'){
            tmp = 3;
        }
        S[MP(s.size(), MP(l[i], t))] |= tmp;
        t = (t * 137 + s[i]) % MOD;
    }
}

bool Find(string s){
    for (int i = 0; i < s.size(); i++){
        l[i + 1] = (l[i] * 71 + s[i]) % MOD;
    }
    int t = 0;
    for (int i = (int)s.size() - 1; i >= 0; i--){
        int tmp = S[MP(s.size(), MP(l[i], t))];
        if ((tmp >> (s[i] - 'a') & 1)) return 1;
        t = (t * 137 + s[i]) % MOD;
    }
    return 0;
}
string s;
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> s;
        Calc(s);
    }
    for (int i = 0; i < m; i++){
        cin >> s;
        if (Find(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}