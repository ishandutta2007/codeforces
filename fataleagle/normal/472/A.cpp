#include <bits/stdc++.h>

using namespace std;

int N;
bool prime[1000100];

int main()
{
    for(int i=2; i<=1000000; i++)
        prime[i]=true;
    for(int i=2; i<=1000000; i++)
        if(prime[i])
            for(int j=i*2; j<=1000000; j+=i)
                prime[j]=false;
    scanf("%d", &N);
    for(int i=2; i<N; i++)
        if(!prime[i] && !prime[N-i])
        {
            printf("%d %d\n", i, N-i);
            break;
        }
    return 0;
}