#include <bits/stdc++.h>

using namespace std;

int N;
int A[200000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", A+i);
        while(A[i]%2==0)
            A[i]/=2;
        while(A[i]%3==0)
            A[i]/=3;
    }
    bool good=true;
    for(int i=0; i<N; i++)
        good&=A[i]==A[0];
    if(good)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}