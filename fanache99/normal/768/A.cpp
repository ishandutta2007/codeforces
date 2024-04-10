//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;

int v[1 + MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    int answer = 0;
    for (int i = 1; i <= n; i++)
        if (v[i] != v[1] && v[i] != v[n])
            answer++;
    cout << answer << "\n";
    return 0;
}