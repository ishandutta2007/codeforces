//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

vector<int> v;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            n /= i;
            v.push_back(i);
        }
    if (n != 1)
        v.push_back(n);
    if (v.size() < k) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < k - 1; i++)
        cout << v[i] << " ";
    int p = 1;
    for (int i = k - 1; i < v.size(); i++)
        p *= v[i];
    cout << p << "\n";
    return 0;
}