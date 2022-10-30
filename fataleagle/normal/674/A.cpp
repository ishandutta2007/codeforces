#include <bits/stdc++.h>

using namespace std;

int N;
int A[5000];
int freq[5001];
int ans[5001];
int idx;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<N; i++)
    {
        for(int j=1; j<=N; j++)
            freq[j]=0;
        idx=-1;
        for(int j=i; j<N; j++)
        {
            int x=A[j];
            freq[x]++;
            if(idx==-1 || freq[x]>freq[idx] || (freq[x]==freq[idx] && x<idx))
                idx=x;
            ans[idx]++;
        }
    }
    for(int i=1; i<=N; i++)
        printf("%d%c", ans[i], " \n"[i==N]);
    return 0;
}