//#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    int n, k;
    cin >> n >> k;
    k = 240 - k;
    int answer = 0;
    while (answer < n && (answer + 1) * 5 <= k) {
        answer++;
        k -= (answer * 5);
    }
    cout << answer << "\n";
    return 0;
}