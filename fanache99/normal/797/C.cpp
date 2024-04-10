//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

char s[1 + MAXN], best[1 + MAXN], Stack[1 + MAXN], answer[1 + MAXN];

int main() {
    cin >> s + 1;
    int n = strlen(s + 1), top = 0, j = 0;
    best[n] = s[n];
    for (int i = n - 1; i >= 1; i--)
        best[i] = min(s[i], best[i + 1]);
    for (int i = 1; i <= n; i++) {
        while (top && Stack[top] <= best[i]) {
            j++;
            answer[j] = Stack[top];
            top--;
        }
        top++;
        Stack[top] = s[i];
    }
    while (top) {
        j++;
        answer[j] = Stack[top];
        top--;
    }
    cout << answer + 1 << "\n";
    return 0;
}