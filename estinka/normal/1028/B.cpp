#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a, b;
    int sum = 5, len = 1;
    while (sum < n) sum += 4, len++;
    a.resize(len, '4');
    a[len - 1] = '5';
    b.resize(len, '5');
    cout << a << "\n" << b << "\n";
    return 0;
}