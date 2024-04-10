#include <bits/stdc++.h>

using namespace std;

int N, Q;
int ans[1000000];

int main()
{
    scanf("%d%d", &N, &Q);
    int one=0, two=1;
    for(int i=0; i<Q; i++)
    {
        int op;
        scanf("%d", &op);
        if(op==1)
        {
            int d;
            scanf("%d", &d);
            if(d<0)
                d+=N;
            one=(one+d)%N;
            two=(two+d)%N;
        }
        else
        {
            one^=1;
            two^=1;
        }
    }
    for(int i=0; i<N/2; i++)
    {
        ans[(one+2*i)%N]=2*i+1;
        ans[(two+2*i)%N]=2*i+2;
    }
    for(int i=0; i<N; i++)
        printf("%d%c", ans[i], " \n"[i==N-1]);
    return 0;
}