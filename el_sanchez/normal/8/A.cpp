#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

string s, a, b;
int len1;

bool find() {
    int p = s.find(a);
    if (p == -1) return 0;
    p += len1;
    p = s.find(b, p);
    return (p != -1);
}

int main() {
    bool b1, b2;
    char tmp[100];
    cin >> s >> a >> b;
    len1 = a.length();     
    
    b1 = find();
    reverse(s.begin(), s.end());
    b2 = find();
    
    if (b1 && b2) cout << "both" << endl;
    if (b1 && !b2) cout << "forward" << endl;
    if (!b1 && b2) cout << "backward" << endl;
    if (!b1 && !b2) cout << "fantasy" << endl;
}