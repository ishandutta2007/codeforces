//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int SIGMA = 26;
const int INF = 10000000;

char a[1 + MAXN], b[1 + MAXN];
int first[SIGMA][1 + MAXN + 1];
int toRight[1 + MAXN + 1], toLeft[1 + MAXN + 1];

int main() {
    cin >> a + 1 >> b + 1;
    int n = strlen(a + 1), m = strlen(b + 1);
    for (int i = 0; i < SIGMA; i++)
        first[i][n + 1] = INF;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < SIGMA; j++)
            first[j][i] = first[j][i + 1];
        if (i)
            first[a[i] - 'a'][i] = i;
    }
    for (int i = 1; i <= m; i++)
        if (toRight[i - 1] == INF)
            toRight[i] = INF;
        else
            toRight[i] = first[b[i] - 'a'][toRight[i - 1] + 1];
    memset(first, 0, sizeof(first));
    for (int i = 0; i < SIGMA; i++)
        first[i][0] = -INF;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j < SIGMA; j++)
            first[j][i] = first[j][i - 1];
        if (i <= n)
            first[a[i] - 'a'][i] = i;
    }
    toLeft[m + 1] = n + 1;
    for (int i = m; i >= 1; i--)
        if (toLeft[i + 1] == -INF)
            toLeft[i] = -INF;
        else
            toLeft[i] = first[b[i] - 'a'][toLeft[i + 1] - 1];
    int answer = 0, first = 0, last = 0;
    for (int i = 0, j = 1; i <= m; i++) {
        while (j < m + 1 && (toLeft[j] <= toRight[i] || j <= i))
            j++;
        if (toLeft[j] > toRight[i] && i + m + 1 - j > answer) {
            answer = i + m + 1 - j;
            first = i;
            last = j;
        }
    }
    if (!answer) {
        cout << "-\n";
        return 0;
    }
    for (int i = 1; i <= first; i++)
        cout << b[i];
    for (int i = last; i <= m; i++)
        cout << b[i];
    return 0;
}