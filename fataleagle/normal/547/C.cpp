#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[200001];
int lp[500001];
bool onshelf[200001];
int cnt[550000];

int main()
{
    for(int i=2; i<=500000; i++) if(!lp[i])
    {
        lp[i]=i;
        for(int j=i*2; j<=500000; j+=i) if(!lp[j])
            lp[j]=i;
    }
    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    int n=0;
    long long ans=0;
    vector<int> factors;
    int a;
    while(Q--)
    {
        scanf("%d", &a);
        if(onshelf[a])
        {
            int x=A[a];
            factors.clear();
            while(x>1)
            {
                factors.push_back(lp[x]);
                x/=lp[x];
            }
            factors.resize(unique(factors.begin(), factors.end())-factors.begin());
            int sum=0;
            for(int i=0; i<(int)(1<<factors.size()); i++)
            {
                int prod=1;
                for(int j=0; j<(int)factors.size(); j++) if((i>>j)&1)
                    prod*=factors[j];
                cnt[prod]--;
                if(__builtin_popcount(i)&1)
                    sum-=cnt[prod];
                else
                    sum+=cnt[prod];
            }
            ans-=sum;
            onshelf[a]=false;
            n--;
        }
        else
        {
            int x=A[a];
            factors.clear();
            while(x>1)
            {
                factors.push_back(lp[x]);
                x/=lp[x];
            }
            factors.resize(unique(factors.begin(), factors.end())-factors.begin());
            int sum=0;
            for(int i=0; i<(int)(1<<factors.size()); i++)
            {
                int prod=1;
                for(int j=0; j<(int)factors.size(); j++) if((i>>j)&1)
                    prod*=factors[j];
                if(__builtin_popcount(i)&1)
                    sum-=cnt[prod];
                else
                    sum+=cnt[prod];
                cnt[prod]++;
            }
            ans+=sum;
            onshelf[a]=true;
            n++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}