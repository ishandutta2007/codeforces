#include <bits/stdc++.h>

using namespace std;

int N;
char S[1000001];

char match(char c)
{
    if(c=='>')
        return '<';
    if(c==']')
        return '[';
    if(c==')')
        return '(';
    if(c=='}')
        return '{';
    return c;
}

int main()
{
    scanf("%s", S);
    N=strlen(S);
    stack<char> stk;
    int ans=0;
    for(int i=0; i<N; i++)
    {
        if(match(S[i])==S[i])
            stk.push(S[i]);
        else
        {
            if(stk.size()==0)
            {
                printf("Impossible\n");
                return 0;
            }
            ans+=stk.top()!=match(S[i]);
            stk.pop();
        }
    }
    if(stk.size()!=0)
    {
        printf("Impossible\n");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}