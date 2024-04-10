//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000000;

char answer[1 + MAXN];

int main() {
    int n, k;
    cin >> n >> k;
    if (n < k || (n > 1 && k == 1)) {
        cout << "-1\n";
        return 0;
    }
    if (k == 1) {
        cout << "a\n";
        return 0;
    }
    for (int i = 1; i <= n - k + 2; i++)
        answer[i] = 'a' + 1 - i % 2;
    for (int i = 3; i <= k; i++)
        answer[n - k + i] = 'a' + i - 1;
    cout << answer + 1 << "\n";
    return 0;
}