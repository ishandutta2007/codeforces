#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s; int k;
    cin >> s >> k;
    int n = s.length();
    if (n % k != 0) { cout << "NO"; return 0;}
    int l = n / k;
    for (int i = 0; i < n; i += l)
        for (int j = i; j < i + l; j++)
            if (s[j] != s[i + i + l - 1 - j]) { cout << "NO"; return 0; }
    cout << "YES";
}