#include <bits/stdc++.h>

using namespace std;

int M, N;
int A[26];

int main()
{
    scanf("%d", &M);
    for(int i=0; i<M; i++)
        scanf("%d", A+i), N+=A[i];
    for(int i=N; i>=1; i--)
    {
        int good=1;
        for(int j=0; j<M; j++)
            good&=(A[j]%i==0);
        if(good)
        {
            int odd=0;
            for(int j=0; j<M; j++)
                odd+=(A[j]/i)%2;
            if(odd<=1)
            {
                for(int j=0; j<M; j++)
                    A[j]/=i;
                string base;
                for(int j=0; j<M; j++) if(A[j]%2==0)
                    for(int k=0; k<A[j]/2; k++)
                        base+='a'+j;
                for(int j=0; j<M; j++) if(A[j]%2==1)
                    for(int k=0; k<A[j]; k++)
                        base+='a'+j;
                for(int j=M-1; j>=0; j--) if(A[j]%2==0)
                    for(int k=0; k<A[j]/2; k++)
                        base+='a'+j;
                int ans=i;
                if(odd==0)
                    ans*=2;
                printf("%d\n", ans);
                for(int j=0; j<i; j++)
                    printf("%s", base.c_str());
                printf("\n");
                return 0;
            }
        }
    }
    printf("0\n");
    for(int i=0; i<M; i++)
        for(int j=0; j<A[i]; j++)
            printf("%c", i+'a');
    printf("\n");
    return 0;
}