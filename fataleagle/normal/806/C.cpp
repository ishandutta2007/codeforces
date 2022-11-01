#include <bits/stdc++.h>

using namespace std;

int N;
long long A[100000];
int B[41];
int C[41];
int D[41];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%lld", A+i);
        if((A[i]&-A[i])==A[i])
            B[__builtin_ctzll(A[i])]++;
        else
        {
            long long x=1, y=0;
            while(x*2<A[i])
                x*=2, y++;
            C[y]++;
        }
    }
    int k=0;
    while(1)
    {
        int i;
        for(i=0; i<41; i++) if(B[i]==0)
            break;
        if(i==0)
            break;
        for(int j=0; j<i; j++)
            B[j]--;
        D[i-1]++;
        k++;
    }
    for(int i=0; i<41; i++)
        C[max(0, i-1)]+=B[i];
    vector<int> ans;
    while(1)
    {
        int d=0;
        for(int i=40; i>=0; i--)
        {
            d+=D[i];
            d-=C[i];
            if(d<0)
                goto out;
        }
        ans.push_back(k);
        k--;
        if(k<0)
            break;
        for(int i=0; i<41; i++) if(D[i]>0)
        {
            D[i]--;
            for(int j=0; j<=i; j++)
                C[j]++;
            break;
        }
    }
    out:;
    if(ans.empty())
        printf("-1\n");
    else
    {
        sort(ans.begin(), ans.end());
        for(auto& it: ans)
            printf("%d ", it);
        printf("\n");
    }
    return 0;
}