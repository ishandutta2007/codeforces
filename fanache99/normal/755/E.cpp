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
    int n, k;
    cin >> n >> k;
    if (n <= 3 || k == 1 || k > 3) {
        cout << "-1\n";
        return 0;
    }
    if (k == 2) {
        if (n == 4) {
            cout << "-1\n";
            return 0;
        }
        cout << n - 1 << "\n";
        for (int i = 1; i < n; i++)
            cout << i << " " << i + 1 << "\n";
    }
    else {
        int m = 3;
        for (int i = 5; i <= n; i++)
            m += i - 3;
        cout << m << "\n" << "1 2\n2 3\n3 4\n";
        for (int i = 5; i <= n; i++) {
            cout << i << " 3\n" << i << " 1\n";
            for (int j = 5; j < i; j++)
                cout << i << " " << j << "\n";
        }
    }
    return 0;
}