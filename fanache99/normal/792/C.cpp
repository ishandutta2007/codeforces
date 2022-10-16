//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

char s[1 + MAXN], s1[1 + MAXN], s2[1 + MAXN], s3[1 + MAXN];

void Solve(char *s, int n, char *answer) {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = (sum + s[i] - '0') % 3;
    if (!sum) {
        for (int i = 1; i <= n; i++)
            answer[i] = s[i];
        return;
    }
    for (int i = 2; i <= n; i++)
        if ((s[i] - '0') % 3 == sum) {
            for (int j = 1; j < i; j++)
                answer[j] = s[j];
            for (int j = i; j < n; j++)
                answer[j] = s[j + 1];
            return;
        }
    int first = 0, second = 0;
    for (int i = 2; i <= n; i++)
        if ((s[i] - '0') % 3 != 0)
            if (!first)
                first = i;
            else
                if (!second)
                    second = i;
                else
                    break;
    if (second) {
        for (int i = 1; i < first; i++)
            answer[i] = s[i];
        for (int i = first + 1; i < second; i++)
            answer[i - 1] = s[i];
        for (int i = second + 1; i <= n; i++)
            answer[i - 2] = s[i];
        return;
    }
    answer[1] = 'a';
}

int main() {
    cin >> s + 1;
    int n = strlen(s + 1);
    Solve(s, n, s1);
    int pointer = 2;
    while (pointer <= n && s[pointer] == '0')
        pointer++;
    if (pointer <= n) {
        Solve(s + pointer - 1, n - pointer + 1, s2);
        pointer++;
        while (pointer <= n && s[pointer] == '0')
            pointer++;
        if (pointer <= n)
            Solve(s + pointer - 1, n - pointer + 1, s3);
    }
    int best = 0, which = 0;
    if (s1[1] != 'a' && strlen(s1 + 1) > best) {
        best = strlen(s1 + 1);
        which = 1;
    }
    if (s2[1] != 'a' && strlen(s2 + 1) > best) {
        best = strlen(s2 + 1);
        which = 2;
    }
    if (s3[1] != 'a' && strlen(s3 + 1) > best) {
        best = strlen(s3 + 1);
        which = 3;
    }
    if (which == 1)
        cout << s1 + 1 << "\n";
    if (which == 2)
        cout << s2 + 1 << "\n";
    if (which == 3)
        cout << s3 + 1 << "\n";
    if (which == 0) {
        for (int i = 1; i <= n; i++)
            if (s[i] == '0') {
                cout << "0\n";
                return 0;
            }
        cout << "-1\n";
    }
    return 0;
}