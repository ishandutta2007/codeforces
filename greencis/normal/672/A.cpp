#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


int main()
{
    stringstream ss;
    for (int i = 1; i <= 1000; ++i)
        ss << i;
    string s;
    ss >> s;
    int x;
    cin >> x;
    cout << s[x - 1];
}