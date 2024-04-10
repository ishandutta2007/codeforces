#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, a, b, x, y;
string s;
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d%d", &a, &b);
        if (x + a > y + 500){
            y = y + b;
            s += 'G';
        }else{
            x = x + a;
            s += 'A';
        }
    }
    cout << s << endl;
}