//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100;

int steps[1 + MAXN];
vector<int> v;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> steps[i];
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    int where = 0;
    for (int step = 1; step <= k; step++) {
        steps[step] %= v.size();
        int after = where;
        for (int i = 1; i <= steps[step]; i++) {
            after++;
            if (after == v.size())
                after = 0;
        }
        cout << v[after] << " ";
        v.erase(v.begin() + after);
        if (after == v.size())
            after = 0;
        where = after;
    }
    return 0;
}