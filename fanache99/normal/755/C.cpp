//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 10000;

bool seen[1 + MAXN];

int main() {
    int n, answer = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == i)
            answer++;
        else
            seen[x]++;
    }
    for (int i = 1; i <= n; i++)
        if (seen[i])
            sum++;
    answer += sum / 2;
    cout << answer << "\n";
    return 0;
}