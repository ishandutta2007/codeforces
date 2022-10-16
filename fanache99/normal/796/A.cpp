//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int Abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int answer = n * 100;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x && x <= k)
            answer = min(answer, 10 * Abs(m - i));
    }
    cout << answer << "\n";
    return 0;
}