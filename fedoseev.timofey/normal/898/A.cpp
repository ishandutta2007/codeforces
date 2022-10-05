#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 10 <= 5) {
        cout << n / 10 * 10 << endl;
    }
    else {
        cout << n + (10 - n % 10) << endl;
    }
}