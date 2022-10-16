//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000000;

char s[1 + MAXN];
int order[1 + MAXN];

int main() {
    cin >> s + 1;
    int n = strlen(s + 1), a = 0, b = n + 1;
    for (int i = 1; i <= n; i++)
        if (s[i] == 'l') {
            b--;
            order[b] = i;
        }
        else {
            a++;
            order[a] = i;
        }
    for (int i = 1; i <= n; i++)
        cout << order[i] << "\n";
    return 0;
}