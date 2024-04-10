// Codeforces Beta Round #5
// Problem C -- Longest Regular Bracket Sequence
#include <cstdio>
#include <cstring>

#define maxN 1000001

using namespace std;

int sum[maxN], stack[maxN];
char str[maxN];

int main()
{
    scanf("%s", str);
    int len = strlen(str);
    sum[0] = 0;
    for(int i = 1; i <= len; ++ i)
        if(str[i - 1] == '(')
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1] - 1;
    int top = 0;
    stack[0] = 0;
    int max = 0, cnt = 1;
    for(int i = 1; i <= len; ++ i)
    {
        while(top >= 0 && sum[stack[top]] > sum[i])
            top --;
        if(sum[stack[top]] == sum[i])
        {
            if(i - stack[top] > max)
                max = i - stack[top], cnt = 0;
            cnt += (i - stack[top] == max);
        }
        else
            stack[++ top] = i;
    }
    printf("%d %d\n", max, cnt);
    return 0;
}