#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, M;
int L[100000];
int R[100000];
int Q[100000];
int req[100002];
int zero[100001];
int ans[100001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
        scanf("%d%d%d", L+i, R+i, Q+i);
    for(int bit=0; bit<31; bit++)
    {
        memset(req, 0, sizeof req);
        memset(zero, 0, sizeof zero);
        for(int i=0; i<M; i++)
            if((Q[i]>>bit)&1)
            {
                req[L[i]]++;
                req[R[i]+1]--;
            }
        for(int i=1; i<=N; i++)
        {
            req[i]+=req[i-1];
            zero[i]=zero[i-1];
            if(req[i])
                ans[i]|=1<<bit;
            else
                zero[i]++;
        }
        for(int i=0; i<M; i++)
            if(!((Q[i]>>bit)&1) && zero[R[i]]-zero[L[i]-1]==0)
            {
                printf("NO\n");
                return 0;
            }
    }
    printf("YES\n");
    for(int i=1; i<=N; i++)
        printf("%d%c", ans[i], " \n"[i==N]);
    return 0;
}