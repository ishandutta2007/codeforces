#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>


using namespace std;


int main() {
    string s;
    char a[100000];
    cin.getline(a, 100000);
    s = string(a);
    int n = (int)s.size();
    char c;
    for (int i = n - 1; i >= 0; i--) {
        if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] >= 'A' && s[i] <= 'Z')) {
            c = s[i];
            break;
        }
    }
    if (c == 'a' || c == 'A' || c == 'o' || c == 'O' || c == 'u' || 
        c == 'U' || c == 'y' || c == 'Y' || c == 'e' || c == 'E' || c == 'i' || c == 'I') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}