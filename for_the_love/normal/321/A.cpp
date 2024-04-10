#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

long long a, b, x, y;
string s;
int main(){
    //scanf("%d%d", &a, &b);
    cin >> a >> b;
    cin >> s;
    if (!a && !b){
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
    }
    for (int i = 0; i < s.size(); i++){
        int flag = 0;
        if (a == 0 && x == 0 && b == 0 && y == 0) flag = 1;
        else if (x != 0 && y == 0 && b == 0 && a % x == 0 && a * x > 0) flag = 1;
        else if (x == 0 && y != 0 && a == 0 && b % y == 0 && b * y > 0) flag = 1;
        else if (x != 0 && y != 0 && a % x == 0 && b % y == 0 && a / x == b / y && a * x > 0 && b * y > 0) flag = 1;
        if (flag){
            puts("Yes");
            return 0;
        }
        if (s[i] == 'U') b--;
        if (s[i] == 'D') b++;
        if (s[i] == 'L') a++;
        if (s[i] == 'R') a--;
        if (!a && !b){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
}