#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100;

char s[1 + MAXN];
vector<int> answer;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n%s", &n, s + 1);
    int length = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == 'B')
            length++;
        else
            if (s[i - 1] == 'B') {
                answer.push_back(length);
                length = 0;
            }
    if (length)
        answer.push_back(length);
    printf("%d\n", answer.size());
    for (auto &it : answer)
        printf("%d ", it);
    return 0;
}