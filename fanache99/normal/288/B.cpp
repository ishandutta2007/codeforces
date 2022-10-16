//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MOD = 1000000007;

int RaiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    int answer = (1LL * RaiseToPower(k, k - 1) * RaiseToPower(n - k, n - k)) % MOD;
    cout << answer << "\n";
    return 0;
}