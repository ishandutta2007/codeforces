#include <bits/stdc++.h>

using namespace std;

int N;
char keys[256];

int main()
{
    scanf("%d", &N);
    char a, b;
    int ans=0;
    for(int i=1; i<N; i++)
    {
        scanf(" %c%c", &a, &b);
        keys[toupper(a)]++;
        if(keys[b])
            keys[b]--;
        else
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}