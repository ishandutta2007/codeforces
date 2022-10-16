//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000;
const int SIGMA = 26;
const int MOD = 1000000007;

char s[1 + MAXN];
int limit[SIGMA], ways[1 + MAXN], best[1 + MAXN];

int main() {
    int n;
    cin >> n >> s + 1;
    for (int i = 0; i < SIGMA; i++)
        cin >> limit[i];
    int longest = 0;
    ways[0] = 1;
    for (int i = 1; i <= n; i++) {
        int j = i, length, finish = 0;
        best[i] = i;
        while (j > finish) {
            finish = max(finish, i - limit[s[j] - 'a']);
            if (j <= finish)
                break;
            ways[i] += ways[j - 1];
            if (ways[i] >= MOD)
                ways[i] -= MOD;
            best[i] = min(best[i], best[j - 1] + 1);
            longest = max(longest, i - j + 1);
            j--;
        }
    }
    cout << ways[n] << "\n" << longest << "\n" << best[n] << "\n";
    return 0;
}