//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>
#include <cassert>

using namespace std;

const int SIZE = 1 << 17;

int pointer = SIZE;
char buffer[SIZE];

const int STATES = 1 << 8;
const int MAXL = 30;
const int X = 240;
const int Y = 204;
const int Z = 170;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

string dp[1 + MAXL][STATES][3];

void Update(string &s, string t) {
    if (s.empty() || s > t)
        s = t;
}

vector<pair<int, int> > forAnd[STATES], forOr[STATES];
string answer[STATES] = {"!x&x", "!(x|y|z)", "!x&!y&z", "!x&!y", "!x&!z&y", "!x&!z", "!(!y&!z|x|y&z)", "!(x|y&z)", "!x&y&z", "!(!y&z|!z&y|x)", "!x&z", "!(!z&y|x)", "!x&y", "!(!y&z|x)", "!x&(y|z)", "!x", "!y&!z&x", "!y&!z", "!(!x&!z|x&z|y)", "!(x&z|y)", "!(!x&!y|x&y|z)", "!(x&y|z)", "!(!x&!y|x&y|z)|!x&!y&z", "!((x|y)&z|x&y)", "!x&y&z|!y&!z&x", "!x&y&z|!y&!z", "!x&z|!y&!z&x", "!x&z|!y&!z", "!x&y|!y&!z&x", "!x&y|!y&!z", "!x&(y|z)|!y&!z&x", "!x|!y&!z", "!y&x&z", "!(!x&z|!z&x|y)", "!y&z", "!(!z&x|y)", "!x&!z&y|!y&x&z", "!x&!z|!y&x&z", "!x&!z&y|!y&z", "!x&!z|!y&z", "!x&y&z|!y&x&z", "!(!x&z|!z&x|y)|!x&y&z", "!(x&y)&z", "!(!z&x|y)|!x&z", "!x&y|!y&x&z", "!(!y&z|x)|!y&x&z", "!x&y|!y&z", "!x|!y&z", "!y&x", "!(!x&z|y)", "!y&(x|z)", "!y", "!x&!z&y|!y&x", "!x&!z|!y&x", "!x&!z&y|!y&(x|z)", "!x&!z|!y", "!x&y&z|!y&x", "!(!x&z|y)|!x&y&z", "!x&z|!y&x", "!x&z|!y", "!x&y|!y&x", "!(!x&!y&z|x&y)", "!x&(y|z)|!y&x", "!x|!y", "!z&x&y", "!(!x&y|!y&x|z)", "!x&!y&z|!z&x&y", "!x&!y|!z&x&y", "!z&y", "!(!y&x|z)", "!x&!y&z|!z&y", "!x&!y|!z&y", "!x&y&z|!z&x&y", "!(!x&y|!y&x|z)|!x&y&z", "!x&z|!z&x&y", "!(!z&y|x)|!z&x&y", "!(x&z)&y", "!(!y&x|z)|!x&y", "!x&z|!z&y", "!x|!z&y", "!z&x", "!(!x&y|z)", "!x&!y&z|!z&x", "!x&!y|!z&x", "!z&(x|y)", "!z", "!x&!y&z|!z&(x|y)", "!x&!y|!z", "!x&y&z|!z&x", "!(!x&y|z)|!x&y&z", "!x&z|!z&x", "!(!x&!z&y|x&z)", "!x&y|!z&x", "!x&y|!z", "!x&(y|z)|!z&x", "!x|!z", "!y&x&z|!z&x&y", "!(!x&y|!y&x|z)|!y&x&z", "!y&z|!z&x&y", "!(!z&x|y)|!z&x&y", "!y&x&z|!z&y", "!(!y&x|z)|!y&x&z", "!y&z|!z&y", "!(!y&!z&x|y&z)", "!x&y&z|!y&x&z|!z&x&y", "!(!x&y|!y&x|z)|!x&y&z|!y&x&z", "!(x&y)&z|!z&x&y", "!(!z&x|y)|!x&z|!z&x&y", "!(x&z)&y|!y&x&z", "!(!y&x|z)|!x&y|!y&x&z", "!(x&y)&z|!z&y", "!x|!y&z|!z&y", "!(y&z)&x", "!(!x&y|z)|!y&x", "!y&z|!z&x", "!y|!z&x", "!y&x|!z&y", "!y&x|!z", "!y&(x|z)|!z&y", "!y|!z", "!(y&z)&x|!x&y&z", "!(!x&y|z)|!x&y&z|!y&x", "!(x&y)&z|!z&x", "!x&z|!y|!z&x", "!(x&z)&y|!y&x", "!x&y|!y&x|!z", "!x&y|!y&z|!z&x", "!(x&y&z)", "x&y&z", "!(x|y|z)|x&y&z", "!x&!y&z|x&y&z", "!x&!y|x&y&z", "!x&!z&y|x&y&z", "!x&!z|x&y&z", "!(!y&!z|x|y&z)|x&y&z", "!(x|y&z)|x&y&z", "y&z", "!(x|y|z)|y&z", "!x&z|y&z", "!x&!y|y&z", "!x&y|y&z", "!x&!z|y&z", "!x&(y|z)|y&z", "!x|y&z", "!y&!z&x|x&y&z", "!y&!z|x&y&z", "!(!x&!z|x&z|y)|x&y&z", "!(x&z|y)|x&y&z", "!(!x&!y|x&y|z)|x&y&z", "!(x&y|z)|x&y&z", "!(!x&!y|x&y|z)|!x&!y&z|x&y&z", "!((x|y)&z|x&y)|x&y&z", "!y&!z&x|y&z", "!y&!z|y&z", "!x&z|!y&!z&x|y&z", "!(x&z|y)|y&z", "!x&y|!y&!z&x|y&z", "!(x&y|z)|y&z", "!x&(y|z)|!y&!z&x|y&z", "!x|!y&!z|y&z", "x&z", "!(x|y|z)|x&z", "!y&z|x&z", "!x&!y|x&z", "!x&!z&y|x&z", "!x&!z|x&z", "!x&!z&y|!y&z|x&z", "!(x|y&z)|x&z", "(x|y)&z", "!(x|y|z)|(x|y)&z", "z", "!x&!y|z", "!x&y|x&z", "!(!y&z|x)|x&z", "!x&y|z", "!x|z", "!y&x|x&z", "!y&!z|x&z", "!y&(x|z)|x&z", "!y|x&z", "!x&!z&y|!y&x|x&z", "!(x&y|z)|x&z", "!x&!z&y|!y&(x|z)|x&z", "!x&!z|!y|x&z", "!y&x|y&z", "!(!x&z|y)|y&z", "!y&x|z", "!y|z", "!x&y|!y&x|x&z", "!x&!z|!y&x|y&z", "!x&y|!y&x|z", "!x|!y|z", "x&y", "!(x|y|z)|x&y", "!x&!y&z|x&y", "!x&!y|x&y", "!z&y|x&y", "!x&!z|x&y", "!x&!y&z|!z&y|x&y", "!(x|y&z)|x&y", "(x|z)&y", "!(x|y|z)|(x|z)&y", "!x&z|x&y", "!(!z&y|x)|x&y", "y", "!x&!z|y", "!x&z|y", "!x|y", "!z&x|x&y", "!y&!z|x&y", "!x&!y&z|!z&x|x&y", "!(x&z|y)|x&y", "!z&(x|y)|x&y", "!z|x&y", "!x&!y&z|!z&(x|y)|x&y", "!x&!y|!z|x&y", "!z&x|y&z", "!(!x&y|z)|y&z", "!x&z|!z&x|x&y", "!x&!y|!z&x|y&z", "!z&x|y", "!z|y", "!x&z|!z&x|y", "!x|!z|y", "(y|z)&x", "!(x|y|z)|(y|z)&x", "!y&z|x&y", "!(!z&x|y)|x&y", "!z&y|x&z", "!(!y&x|z)|x&z", "!y&z|!z&y|x&y", "!x&!y|!z&y|x&z", "(x|y)&z|x&y", "!(x|y|z)|(x|y)&z|x&y", "x&y|z", "!x&!y|x&y|z", "x&z|y", "!x&!z|x&z|y", "y|z", "!x|y|z", "x", "!y&!z|x", "!y&z|x", "!y|x", "!z&y|x", "!z|x", "!y&z|!z&y|x", "!y|!z|x", "x|y&z", "!y&!z|x|y&z", "x|z", "!y|x|z", "x|y", "!z|x|y", "x|y|z", "!x|x"};


void Precompute() {
    for (int j = 0; j < STATES; j++)
        for (int a = 0; a < STATES; a++)
            for (int b = 0; b < STATES; b++) {
                if ((a & b) == j)
                    forAnd[j].push_back(make_pair(a, b));
                if ((a | b) == j)
                    forOr[j].push_back(make_pair(a, b));
            }
    for (int i = 1; i <= MAXL; i++)
        for (int j = 0; j < STATES; j++) {
            if (i == 1) {
                if (j == X)
                    Update(dp[i][j][2], "x");
                if (j == Y)
                    Update(dp[i][j][2], "y");
                if (j == Z)
                    Update(dp[i][j][2], "z");
            }
            if (i >= 2 && !dp[i - 2][j][0].empty())
                Update(dp[i][j][2], "(" + dp[i - 2][j][0] + ")");
            if (i >= 1 && !dp[i - 1][j ^ (STATES - 1)][2].empty())
                Update(dp[i][j][2], "!" + dp[i - 1][j ^ (STATES - 1)][2]);
            if (!dp[i][j][2].empty())
                Update(dp[i][j][1], dp[i][j][2]);
            for (int k = 1; k < i; k++)
                for (auto &it : forAnd[j]) {
                    int a = it.first, b = it.second;
                    if (!dp[k][a][2].empty() && !dp[i - k - 1][b][1].empty())
                        Update(dp[i][j][1], dp[k][a][2] + "&" + dp[i - k - 1][b][1]);
                }
            if (!dp[i][j][1].empty())
                Update(dp[i][j][0], dp[i][j][1]);
            for (int k = 1; k < i; k++)
                for (auto &it : forOr[j]) {
                    int a = it.first, b = it.second;
                    if (!dp[k][a][1].empty() && !dp[i - k - 1][b][0].empty())
                        Update(dp[i][j][0], dp[k][a][1] + "|" + dp[i - k - 1][b][0]);
                }
        }
    cout << "{";
    for (int i = 0; i < STATES; i++) {
        string best;
        for (int j = 1; j <= MAXL; j++) {
            if (!dp[j][i][0].empty())
                Update(best, dp[j][i][0]);
            if (!dp[j][i][1].empty())
                Update(best, dp[j][i][1]);
            if (!dp[j][i][2].empty())
                Update(best, dp[j][i][2]);
            if (!best.empty())
                break;
            //cout << i << " " << best << "\n";
        }
        best = '"' + best + '"';
        cout << best << ", ";
        //cout << i << " " << best << "\n";
    }
    cout << "}";
   // cout << dp[4][3][0] << "\n";
}

int main() {
    int n;
    cin >> n;
    for (int x = 1; x <= n; x++) {
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < 8; j++)
            if (s[j] == '1')
                mask += (1 << j);
        cout << answer[mask] << "\n";
    }
    return 0;
}