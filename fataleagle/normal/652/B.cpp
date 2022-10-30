#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    sort(A, A+N);
    vector<int> z;
    for(int i=0, j=N-1; i<j; i++, j--)
    {
        z.push_back(A[i]);
        z.push_back(A[j]);
    }
    if(N%2==1)
        z.push_back(A[N/2]);
    bool bad=false;
    for(int i=0; i<N-1; i++)
    {
        if(i%2==0 && z[i]>z[i+1])
            bad=true;
        if(i%2==1 && z[i]<z[i+1])
            bad=true;
    }
    if(bad)
        printf("Impossible\n");
    else
    {
        for(int i=0; i<N; i++)
            printf("%d ", z[i]);
        printf("\n");
    }
    return 0;
}