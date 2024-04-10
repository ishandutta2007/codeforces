#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>

using namespace std;

int main()
{
    string s;
    cin >> s;
    set<char> a;
    for (int i=0; i<s.length(); i++) a.insert(s[i]);
    if (a.size()%2) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
    return 0;
}