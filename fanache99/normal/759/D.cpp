//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 5000;
const int MOD = 1000000007;
const int SIGMA = 26;

int dp[1 + MAXN];
int sum[1 + MAXN], subtract[SIGMA][1 + MAXN];
char s[1 + MAXN];
vector<int> letters;
bool seen[SIGMA];

void Add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void Subtract(int &a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
}

int main() {
    int n;
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i++)
        if (s[i] != s[i - 1])
            letters.push_back(s[i] - 'a');
    int m = letters.size();
    for (int i = 0; i <= n; i++)
        sum[i] = 1;
    for (int i = 1; i <= m; i++) {
        int now = letters[i - 1];
        for (int j = 1; j <= n; j++) {
            dp[j] = sum[j - 1];
            Subtract(dp[j], subtract[now][j - 1]);
        }
        int add = 0;
        for (int j = 1; j <= n; j++) {
            Add(add, dp[j]);
            Subtract(sum[j], subtract[now][j]);
            Add(sum[j], add);
            subtract[now][j] = add;
        }
    }
    int answer = sum[n];
    Subtract(answer, sum[n - 1]);
    cout << answer << "\n";
    return 0;
}