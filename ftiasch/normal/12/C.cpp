// Codeforces Beta Round #12
// Problem C -- Fruits
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> a, b;
map<string, int> c;

int main()
{
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i != n; ++ i)
        cin >> a[i];
    c.clear();
    for(int i = 0; i != m; ++ i)
    {
        string name;
        cin >> name;
        c[name] ++;
    }
    b.clear();
    for(map<string, int>::iterator iter = c.begin(); iter != c.end(); ++ iter)
        b.push_back(iter->second);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int temp = 0;
    for(int i = 0; i != b.size(); ++ i)
        temp += a[b.size() - 1 - i] * b[i];
    cout << temp << " ";
    temp = 0;
    for(int i = 0; i != b.size(); ++ i)
        temp += a[n - b.size() + i] * b[i];
    cout << temp << "\n";
    return 0;
}