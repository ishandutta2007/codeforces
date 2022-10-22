#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string b;
        cin >> n >> b; 
        string a(1, '1');
        for (int i = 1; i < n; i++)
        {
            if (b[i] + '1' == a[i - 1] + b[i - 1]) a.push_back('0');
            else a.push_back('1');
        }
        cout << a << "\n";
    }
    return 0;
}