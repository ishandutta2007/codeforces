#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    int a;
    cin >> s >> a;
    if (s=="front") cout << (a==1 ? "L" : "R") << endl;
    else cout << (a==1 ? "R" : "L") << endl;
    return 0;
}