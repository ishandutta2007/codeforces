#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;
    while (s.length() && s[0] == '0') s = s.substr(1,s.length()-1);
    int i  =0;
    for (; i < s.length(); ++i) {
        if (s[i]=='0')break;
    }
    if (i < s.length()) s.erase(i,1);
    else s.erase(0,1);
    cout<<s;
}