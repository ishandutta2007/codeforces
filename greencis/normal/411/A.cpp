#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

string s;
bool isA=false,isa=false,is1=false;

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') isA = true;
        if (s[i] >= 'a' && s[i] <= 'z') isa = true;
        if (s[i] >= '0' && s[i] <= '9') is1 = true;
    }
    if (s.length() >= 5 && isA && isa && is1) cout << "Correct"; else cout << "Too weak";
    return 0;
}