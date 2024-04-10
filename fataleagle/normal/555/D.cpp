#include <bits/stdc++.h>

using namespace std;

struct tree
{
    set<long long> s;
    long long find_nearest_L(long long x)
    {
        auto it=s.upper_bound(x);
        if(it==s.begin())
            return -1;
        return *--it;
    }
    long long find_nearest_R(long long x)
    {
        auto it=s.lower_bound(x);
        if(it==s.end())
            return -1;
        return *it;
    }
} T;

int N, M;
long long X[200000];
map<long long, int> Y;

int main()
{
    scanf("%d%d", &N, &M);
    long long a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%lld", &a);
        a+=1000000000;
        X[i]=a;
        Y[a]=i;
        T.s.insert(a);
    }
    for(int i=0; i<M; i++)
    {
        scanf("%lld%lld", &a, &b);
        a=X[a-1];
        while(b>=1)
        {
            long long c=T.find_nearest_L(a+b);
            long long d=T.find_nearest_R(c-(b-(c-a)));
            if(b-(c-a)<=0 || c==d)
            {
                a=c;
                break;
            }
            if(a==d)
                b%=2*(c-a);
            else
            {
                b-=c-a;
                b-=c-d;
                a=d;
            }
        }
        printf("%d\n", Y[a]+1);
    }
    return 0;
}