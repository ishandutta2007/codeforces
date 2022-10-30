#include <bits/stdc++.h>

using namespace std;

int B, N, M;
int num[10000];
bool used[101];

int main()
{
    scanf("%d%d", &B, &N);
    if(B==2)
    {
        printf("YES\n");
        return 0;
    }
    while(N>0)
    {
        num[M++]=N%B;
        N/=B;
    }
    for(int i=0; i<M; i++)
    {
        if(num[i]==B-1)
        {
            int j=i;
            for(; j<M && num[j]==B-1; j++);
            for(int k=i; k<j; k++)
                num[k]=0;
            if(j==M)
                num[M++]=1;
            else
                num[j]++;
            used[i]=true;
        }
    }
    for(int i=0; i<M; i++)
    {
        if(num[i]==1)
        {
            if(used[i])
            {
                printf("NO\n");
                return 0;
            }
            used[i]=true;
        }
        else if(num[i]!=0)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}