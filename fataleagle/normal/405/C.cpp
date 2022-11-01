#include <bits/stdc++.h>

using namespace std;

int N, Q;
int diag[1000];
int ones;

int main()
{
    int a;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
        {
            scanf("%d", &a);
            if(i==j)
            {
                diag[i]=a;
                if(a==1)
                    ones++;
            }
        }
    scanf("%d", &Q);
    for(int i=0; i<Q; i++)
    {
        scanf("%d", &a);
        switch(a)
        {
        case 3:
            putchar('0'+(ones%2));
            break;
        default:
            scanf("%d", &a);
            if(diag[a-1]==0)
                ones++;
            else
                ones--;
            diag[a-1]^=1;
        }
    }

    return 0;
}