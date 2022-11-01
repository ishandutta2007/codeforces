#include <bits/stdc++.h>

using namespace std;

map<char, int> m{{'A', 1}, {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1}, {'Y', 1}};
int N;
char S[500003];
int A[500005];

int main()
{
    scanf("%s", S+1);
    N=strlen(S+1);
    for(int i=1; i<=N; i++)
        A[i]=m[S[i]];
    for(int i=N; i>=1; i--)
        A[i]+=A[i+1];
    double ans=0.0;
    long long tot=0;
    for(int i=1; i<=N; i++)
    {
        tot+=A[i]-A[N-i+2];
        ans+=1.0*tot/i;
    }
    printf("%.9lf\n", ans);
    return 0;
}