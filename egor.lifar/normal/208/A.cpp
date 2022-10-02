#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1; i < n - 1; i++){
        if(s[i] == 'U' && s[i - 1] == 'W' && s[i + 1] == 'B'){
            s[i] = '0';
            s[i - 1] = '0';
            s[i + 1] = '0';
        }
    }
    for(int i = 0; i < n; i++){
        if(i > 0 && s[i] == '0' && s[i - 1] != '0'){
            cout << ' ';
        }
        if(s[i] != '0'){
            cout << s[i];
        }
    }
    return 0;
}