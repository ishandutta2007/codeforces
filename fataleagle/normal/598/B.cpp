#include <bits/stdc++.h>

using namespace std;

char S[10001];

int main()
{
    scanf("%s", S);
    int M;
    scanf("%d", &M);
    while(M--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l--, r--;
        k%=(r-l+1);
        rotate(S+l, S+r+1-k, S+r+1);
    }
    printf("%s\n", S);
    return 0;
}