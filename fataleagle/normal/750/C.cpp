#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);
    int maxDiv2=-0x3f3f3f3f, minDiv1=0x3f3f3f3f;
    int r=0;
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(b==1)
        {
            minDiv1=min(minDiv1, r);
            r+=a;
        }
        else
        {
            maxDiv2=max(maxDiv2, r);
            r+=a;
        }
    }
    if(maxDiv2>=minDiv1)
        printf("Impossible\n");
    else if(maxDiv2==-0x3f3f3f3f)
        printf("Infinity\n");
    else
        printf("%d\n", 1899-maxDiv2+r);
    return 0;
}