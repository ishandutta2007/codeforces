#include <bits/stdc++.h>

using namespace std;

int N;
char S[1000];

int main()
{
    scanf("%d", &N);
    scanf("%s", S);
    for(int len=1; len<=N; len++)
    {
        for(int i=0; i<N; i++)
        {
            bool good=true;
            for(int j=0; j<5; j++)
                good&=i+j*len<N && S[i+j*len]=='*';
            if(good)
            {
                printf("yes\n");
                return 0;
            }
        }
    }
    printf("no\n");
    return 0;
}