#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    string s = "<3", t;

    cin >> n;
    while (n--) cin >> t, s += t + "<3";
    
    cin >> t;
    int j = 0;
    for (int i = 0;;)
    {
        while (j < int(t.size()) && s[i] != t[j]) j++;
        if (j == int(t.size())) break;
        if (++i == int(s.size())) break;
        j++;
    }
    
    puts(j == int(t.size()) ? "no" : "yes");
}