#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int x=0;
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a-b<0)
            x--;
        else if(a-b>0)
            x++;
    }
    if(x>0)
        printf("Mishka\n");
    else if(x<0)
        printf("Chris\n");
    else
        printf("Friendship is magic!^^\n");
    return 0;
}