

#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;



int main() {                               
    char s[1000];
    cin >> s;
    if((s[0] > 'a' || s[0] == 'a') && (s[0] < 'z' || s[0] == 'z')) {
      s[0] = s[0] +'A' - 'a';
    } 
    cout << s;
    return 0;
}