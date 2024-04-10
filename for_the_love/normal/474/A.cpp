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
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;
typedef pair<DB, DB> DPI;
const DB eps = 1e-8;
const int N = 1e4 + 7;
const int INF = 1e9 + 7;
const int MOD = 2345699;

string s[3];

char str[N], ch;

int main(){
s[0] = "qwertyuiop";
s[1] = "asdfghjkl;";
s[2] = "zxcvbnm,./";
    scanf("%c", &ch);
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++){
        for (int j = 0; j < 3; j++)
        for (int k = 0; k < s[j].size(); k++)
        if (s[j][k] == str[i]){
            if (ch == 'R'){
                printf("%c", s[j][k - 1]);
            }else if (ch == 'L'){
                printf("%c", s[j][k + 1]);
            }
        }
    }
}