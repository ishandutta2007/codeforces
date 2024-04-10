#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

const int N = 50000;
const int M = 50;
const int INF = 1000000000;

int n;
char string[N + 1];

int minimum[N + 1][M + 1];
std::vector <int> indices[26];

void update(int &x, int a) {
    x = std::min(x, a);
}

int main() {
    scanf("%s", string);
    n = strlen(string);
    for (int i = 0; i < n; ++ i) {
        indices[string[i] - 'a'].push_back(i);
    }
    for (int i = 0; i <= n; ++ i) {
        for (int j = 0; j <= M; ++ j) {
            minimum[i][j] = INF;
        }
    }
    minimum[n][0] = -1;
    for (int i = n - 1; i >= 0; -- i) {
        minimum[i][0] = -1;
        for (int j = 1; j <= M; ++ j) {
            minimum[i][j] = minimum[i + 1][j];
            std::vector <int> &v = indices[string[i] - 'a'];
            std::vector <int> :: iterator iter = std::lower_bound(v.begin(), v.end(), minimum[i + 1][j - 1] + 1);
            if (iter != v.end()) {
                minimum[i][j] = std::min(minimum[i][j], *iter);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 1; j <= M; ++ j) {
            if (minimum[i][j] <= i) {
                answer = std::max(answer, (j << 1) - (minimum[i][j] == i));
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 1; j <= M; ++ j) {
            if (minimum[i][j] <= i && (j << 1) - (minimum[i][j] == i) == answer) {
                std::vector <int> palindrome;
                while (j) {
                    if (minimum[i][j] != minimum[i + 1][j]) {
                        palindrome.push_back(string[i]);
                        j --;
                    }
                    i ++;
                }
                for (int i = (int)palindrome.size() - 1; i >= answer % 2; -- i) {
                    putchar(palindrome[i]);
                }
                for (int i = 0; i < (int)palindrome.size(); ++ i) {
                    putchar(palindrome[i]);
                }
                puts("");
                return 0;
            }
        }
    }
    return 0;
}