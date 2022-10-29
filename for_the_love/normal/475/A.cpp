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
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

string s[6];

int main(){
    s[0] = "+------------------------+";
    s[1] = "|O.O.O.O.O.O.O.#.#.#.#.|D|)";
    s[2] = "|O.O.O.O.O.O.#.#.#.#.#.|.|";
    s[3] = "|O.......................|";
    s[4] = "|O.O.O.O.O.O.#.#.#.#.#.|.|)";
    s[5] = "+------------------------+";
    for (int i = 0; i < 26; i++)
    for (int j = 0; j < 6; j++)
    if (s[j][i] == 'O') s[j][i] = '#';


    int n;
    scanf("%d", &n);
    for (int i = 0; i < 26 && n; i++)
    for (int j = 0; j < 6 && n; j++)
    if (s[j][i] == '#'){
        s[j][i] = 'O';
        n--;
    }
    for (int i = 0; i < 6; i++) cout << s[i] << endl;
}