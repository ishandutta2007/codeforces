//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

long long n;

void Move(long long &node, long long &power2, char type) {
    if (type == 'U') {
        if (node == (n + 1) / 2)
            return;
        if ((node + power2) % (4 * power2) != 0)
            node += power2;
        else
            node -= power2;
        power2 *= 2;
    }
    else {
        if (power2 == 1)
            return;
        power2 /= 2;
        if (type == 'L')
            node -= power2;
        else
            node += power2;
    }
}

int main() {
    int q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        long long node;
        string s;
        cin >> node >> s;
        long long power2 = 1;
        while (node % (power2 * 2) == 0)
            power2 *= 2;
        for (auto &type : s)
            Move(node, power2, type);
        cout << node << "\n";
    }
    return 0;
}