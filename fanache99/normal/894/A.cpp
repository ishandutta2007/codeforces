#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 100;

char s[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1), answer = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
                    answer++;
    printf("%d\n", answer);
    return 0;
}