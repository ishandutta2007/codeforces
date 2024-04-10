#include <bits\stdc++.h>

using namespace std;

int main()
{
    string s = "Q";
    int n; cin >> n;
    for (int i = 1; i <= 1000; i++) s += to_string(i);
    cout << s[n];
}