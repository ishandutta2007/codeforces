
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;
 
// #define MAXN  500000
 
// vector <int> v[MAXN];
int main()
{
    int n, t;
    string s;
    cin >> n >> t >> s;
    for(int j = 0; j < t; j++){
        string s2 = s;
        for(int i = 0; i < n; i++){
            if(s[i] == 'B' && i < n - 1 && s[i + 1] == 'G'){
                s2[i] = s[i + 1];
                s2[i + 1] = s[i];
            }
        }
        s = s2;
    }
    cout << s << "\n";
    return 0;
}