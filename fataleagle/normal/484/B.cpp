#include <bits/stdc++.h>

using namespace std;

int N;
bool A[2000001];
int B[2000001];

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[a]=true;
    }
    for(int i=1; i<=2000000; i++)
    {
        if(A[i])
            B[i]=i;
        else
            B[i]=B[i-1];
    }
    int ans=0;
    for(int i=1; i<=2000000; i++)
        if(A[i])
            for(int j=i*2; j<=2000000; j+=i)
                if(B[j-1]>=j-i)
                    ans=max(ans, B[j-1]-j+i);
    printf("%d\n", ans);
    return 0;
}