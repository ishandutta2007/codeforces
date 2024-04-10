#include <bits/stdc++.h>

using namespace std;

int N;
int X[4];
int Y[4];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", X+i, Y+i);
    int mx=1001, Mx=-1001, my=1001, My=-1001;
    for(int i=0; i<N; i++)
    {
        mx=min(mx, X[i]);
        Mx=max(Mx, X[i]);
        my=min(my, Y[i]);
        My=max(My, Y[i]);
    }
    if(mx!=Mx && my!=My)
        printf("%d\n", (My-my)*(Mx-mx));
    else
        printf("-1\n");
    return 0;
}