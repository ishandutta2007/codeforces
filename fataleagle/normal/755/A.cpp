#include <bits/stdc++.h>

using namespace std;

int N;
int pr[2000000];

int main()
{
    for(int i=2; i<2000000; i++)
        pr[i]=1;
    for(int i=2; i<2000000; i++) if(pr[i])
        for(int j=i+i; j<2000000; j+=i)
            pr[j]=0;
    scanf("%d", &N);
    for(int i=1; i<=1000; i++) if(!pr[i*N+1])
        return 0*printf("%d\n", i);
    return 0;
}