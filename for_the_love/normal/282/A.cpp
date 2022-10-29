#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, x;
char s[100];
int main(){
    scanf("%d", &n);
    while (n--){
        scanf("%s", s);
        if (s[0] == '+' || s[1] == '+') x++; else x--;
    }
    printf("%d\n", x);
}