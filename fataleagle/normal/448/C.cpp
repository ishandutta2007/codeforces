#include <bits/stdc++.h>

using namespace std;

int N;
int A[5000];

int solve(int l, int r, int h)
{
    if(l==r)
        return 1;
    int cnt=0;
    for(int i=l; i<=r; i++)
        if(A[i]>h)
            cnt++;
    int mini=0x3f3f3f3f;
    for(int i=l; i<=r; i++)
        if(A[i]>h)
            mini=min(mini, A[i]-h);
    if(mini==0x3f3f3f3f)
        return 0;
    h+=mini;
    int ret=mini;
    for(int i=l, j; i<=r;)
    {
        if(A[i]<=h)
        {
            i++;
            continue;
        }
        j=i;
        while(j<r && A[j+1]>h)
            j++;
        ret+=solve(i, j, h);
        i=j+1;
    }
    return min(cnt, ret);
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    printf("%d\n", solve(0, N-1, 0));
    return 0;
}