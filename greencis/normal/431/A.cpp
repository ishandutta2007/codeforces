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

int u[9999];

int main()
{
    int a1,a2,a3,a4,c1,c2,c3,c4;
    string s;
    cin >> a1>>a2>>a3>>a4>>s;
    for (int i = 0; s[i]; ++i)
        if (s[i]=='1') ++c1;
    else if (s[i]=='2') ++c2;
    else if (s[i]=='3') ++c3;
    else if (s[i]=='4') ++c4;
    cout << a1*c1+a2*c2+a3*c3+a4*c4;
}