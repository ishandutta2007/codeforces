#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B; cin >> A >> B;
    int N = count(A.begin(), A.end(), '1');
    int M = count(B.begin(), B.end(), '1');

    if ((N + 1) / 2 >= (M + 1) / 2)
        cout << "YES\n";
    else
        cout << "NO\n";
}