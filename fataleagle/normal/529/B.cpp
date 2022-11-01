#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> A[2000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    int ans=0x7fffffff;
    for(int h=1; h<=1000; h++)
    {
        vector<int> gains;
        int sum=0;
        int lie=0;
        for(int i=0; i<N; i++)
        {
            if(A[i].second>h)
            {
                if(A[i].first>h)
                    goto bad;
                lie++;
                sum+=A[i].second;
            }
            else if(A[i].first>h)
                sum+=A[i].first;
            else
            {
                sum+=A[i].first;
                gains.push_back(A[i].second-A[i].first);
            }
        }
        if(lie>N/2)
            goto bad;
        sort(gains.rbegin(), gains.rend());
        while(lie+1<=N/2 && !gains.empty() && gains.back()<0)
        {
            sum+=gains.back();
            gains.pop_back();
            lie++;
        }
        ans=min(ans, sum*h);
        bad:;
    }
    printf("%d\n", ans);
    return 0;
}