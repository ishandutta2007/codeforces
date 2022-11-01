#include <bits/stdc++.h>

using namespace std;

int N;
int A[100002];
int B[100002];

bool test(int i, int j)
{
    reverse(A+i, A+j+1);
    copy(A+1, A+1+N, B+1);
    sort(B+1, B+1+N);
    bool ret=equal(A+1, A+1+N, B+1);
    reverse(A+i, A+j+1);
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    A[0]=-1000000001;
    A[N+1]=1000000001;
    int idx=-1, idx2=-1;
    bool prev=false;
    for(int i=1; i<=N+1; i++)
        if(A[i]<A[i-1])
        {
            if(prev)
                continue;
            if(idx==-1)
                prev=true, idx=i;
            else
                goto fail;
        }
        else
        {
            if(prev)
                idx2=i-1;
            prev=false;
        }
    if(idx==-1)
    {
        printf("yes\n1 1\n");
        return 0;
    }
    if(idx>0 && test(idx-1, idx2))
        printf("yes\n%d %d\n", idx-1, idx2);
    else if(idx>0 && test(idx, idx2))
        printf("yes\n%d %d\n", idx, idx2);
    else
        goto fail;
    return 0;
    fail:;
    printf("no\n");
    return 0;
}