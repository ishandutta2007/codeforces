#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char ch[9], s[999], L[999], R[999], st[3][99] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

int main()
{
    for (int k = 0; k < 3; k ++)
        for (int i = 0; i < 10; i ++)
        {
            if (i < 9)
                L[st[k][i]] = st[k][i + 1];
            if (i) R[st[k][i]] = st[k][i - 1];
        }
        
    
    scanf("%s", ch);
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i ++)
        printf("%c", ch[0] == 'L' ? L[s[i]] : R[s[i]]);
    return 0;
}