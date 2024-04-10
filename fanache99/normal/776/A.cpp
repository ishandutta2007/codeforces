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

int main() {
    string a, b;
    int n;
    cin >> a >> b >> n;
    for (int i = 1; i <= n; i++) {
        cout << a << " " << b << "\n";
        string x, y;
        cin >> x >> y;
        if (a == x)
            a = y;
        else
            if (a == y)
                a = x;
            else
                if (b == x)
                    b = y;
                else
                    b = x;
    }
    cout << a << " " << b << "\n";
    return 0;
}