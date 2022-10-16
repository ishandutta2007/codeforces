//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int main() {
    string a, b;
    cin >> a >> b;
    if (a == b)
        cout << "-1\n";
    else
        cout << max(a.size(), b.size()) << "\n";
    return 0;
}