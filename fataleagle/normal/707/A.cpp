#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    bool ok=true;
    for(int i=0; i<N*M; i++)
    {
        char c;
        scanf(" %c", &c);
        if(c!='B' && c!='W' && c!='G')
            ok=false;
    }
    if(ok)
        printf("#Black&White\n");
    else
        printf("#Color\n");
    return 0;
}