//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    int n, k, cycles = 0, node = 1;
    long long answer = 1;
    cin >> n >> k;
    if (k > n / 2)
        k = n - k;
    for (int i = 1; i <= n; i++) {
        int neighbour = node + k;
        if (neighbour > n)
            neighbour -= n;
        if (neighbour < node && neighbour != 1)
            cycles++;
        answer += cycles + 1;
        if (neighbour < node)
            cycles++;
        node = neighbour;
        cout << answer << " ";
    }
    return 0;
}