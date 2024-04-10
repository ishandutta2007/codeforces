// Codeforces Beta Round #12
// Problem B -- Correct Solution?
#include <cstdio>
#include <cstring>

using namespace std;

int a, b, d[10];
char bb[1024];

int main()
{
    scanf("%d%s", &a, bb);
    sscanf(bb, "%d", &b);
    if(a) 
    {
        for(int i = 0; i != 10; ++ i)
            d[i] = 0;
        while(a)
            d[a % 10] ++, a /= 10;        
        int c = 0;
        for(int i = 1; i != 10; ++ i)
            if(d[i])
            {
                c = i, d[i] --;
                break;
            }
        for(int i = 0; i != 10; ++ i)
            while(d[i])
                c = c * 10 + i, d[i] --;
        printf(bb[0] != '0' && b == c? "OK\n": "WRONG_ANSWER\n");
    }
    else
        printf(strcmp(bb, "0") == 0 ? "OK\n": "WRONG_ANSWER\n");
    return 0;
}