#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    string S; cin >> S;

    int ones = count(S.begin(), S.end(), 'n');
    int zeros = count(S.begin(), S.end(), 'z');

    for (int i = 0; i < ones; ++i)
        cout << "1 ";
    for (int i = 0; i < zeros; ++i)
        cout << "0 ";
    cout << "\n";
}