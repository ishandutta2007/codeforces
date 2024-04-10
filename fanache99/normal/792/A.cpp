//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 200000;

int v[1 + MAXN];

int main() {
    int n, many, answer = 2000000001;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    for (int i = 1; i < n; i++)
        if (v[i + 1] - v[i] < answer) {
            answer = v[i + 1] - v[i];
            many = 1;
        }
        else
            if (v[i + 1] - v[i] == answer)
                many++;
    cout << answer << " " << many << "\n";
    return 0;
}