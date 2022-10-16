//#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int INF = 1000000000;
const int LIMIT = 1900;

int main() {
    int n;
    cin >> n;
    int low = -INF, high = INF;
    for (int i = 1; i <= n; i++) {
        int add, division;
        cin >> add >> division;
        if (division == 1)
            if (high < LIMIT) {
                cout << "Impossible\n";
                return 0;
            }
            else
                low = max(low, LIMIT);
        else
            if (low >= LIMIT) {
                cout << "Impossible\n";
                return 0;
            }
            else
                high = min(high, LIMIT - 1);
        if (low != -INF)
            low += add;
        if (high != INF)
            high += add;
    }
    if (high == INF)
        cout << "Infinity\n";
    else
        cout << high << "\n";
    return 0;
}