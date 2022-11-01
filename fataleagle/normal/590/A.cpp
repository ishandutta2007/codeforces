#include <bits/stdc++.h>

using namespace std;

int N;
int A[500001];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    int ans=0;
    for(int i=0, j; i<N; i=j+1)
    {
        for(j=i; j+1<N && A[j]!=A[j+1]; j++);
        ans=max(ans, (j-i)/2);
        if(A[i]==A[j])
        {
            for(int k=i; k<=j; k++)
                A[k]=A[i];
        }
        else
        {
            int l=i+(j-i+1)/2;
            for(int k=i; k<l; k++)
                A[k]=A[i];
            for(int k=l; k<=j; k++)
                A[k]=A[j];
        }
    }
    printf("%d\n", ans);
    for(int i=0; i<N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}