//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 500000;

string s[1 + MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = n - 1; i >= 1; i--) {
        int a = s[i].size(), b = s[i + 1].size();
        int j = 1;
        while (j < a && j < b && s[i][j] == s[i + 1][j])
            j++;
        if (j == a)
            continue;
        if (j < b && s[i][j] < s[i + 1][j])
            continue;
        for (int k = j; k < a; k++)
            s[i].pop_back();
    }
    for (int i = 1; i <= n; i++)
        cout << s[i] << "\n";
    return 0;
}