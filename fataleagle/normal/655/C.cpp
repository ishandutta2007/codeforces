#include <bits/stdc++.h>

using namespace std;

int N, K;
char S[100001];
int R[100001];

int main()
{
    scanf("%d%d", &N, &K);
    K++;
    scanf("%s", S);
    int last=N;
    for(int i=N-1; i>=0; i--)
    {
        R[i]=last;
        if(S[i]=='0')
            last=i;
    }
    int l=0, r=0, m=0;
    while(S[l]!='0')
        l++;
    r=m=l;
    int cnt=1;
    while(cnt<K)
        cnt+=S[++r]=='0';
    while(R[m]-l<r-R[m])
        m=R[m];
    int ans=min(max(m-l, r-m), max(R[m]-l, r-R[m]));
    while(r<N)
    {
        l++;
        while(S[l]!='0')
            l++;
        r++;
        while(r<N && S[r]!='0')
            r++;
        if(r==N)
            break;
        while(R[m]-l<r-R[m])
            m=R[m];
        ans=min(ans, min(max(m-l, r-m), max(R[m]-l, r-R[m])));
    }
    printf("%d\n", ans);
    return 0;
}