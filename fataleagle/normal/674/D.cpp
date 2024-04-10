#include <bits/stdc++.h>

using namespace std;

int N, Q;
multiset<long long> all;
long long A[100001];
int P[100001];
int deg[100001];
long long V[100001];
multiset<long long> S[100001];

void add(int i)
{
    if(!S[i].empty())
    {
        all.insert(*S[i].begin()+A[i]/(deg[i]+1));
        all.insert(*S[i].rbegin()+A[i]/(deg[i]+1));
    }
}

void rem(int i)
{
    if(!S[i].empty())
    {
        all.erase(all.find(*S[i].begin()+A[i]/(deg[i]+1)));
        all.erase(all.find(*S[i].rbegin()+A[i]/(deg[i]+1)));
    }
}

void init()
{
    all.clear();
    for(int i=1; i<=N; i++)
        deg[i]=0, V[i]=0, S[i].clear();
    for(int i=1; i<=N; i++)
        deg[i]++, deg[P[i]]++;
    for(int i=1; i<=N; i++)
    {
        V[i]+=A[i]-A[i]/(deg[i]+1)*deg[i];
        V[P[i]]+=A[i]/(deg[i]+1);
    }
    for(int i=1; i<=N; i++)
        S[P[i]].insert(V[i]);
    for(int i=1; i<=N; i++) if(!S[i].empty())
    {
        all.insert(*S[i].begin()+A[i]/(deg[i]+1));
        all.insert(*S[i].rbegin()+A[i]/(deg[i]+1));
    }
}

int main()
{
    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++)
        scanf("%lld", A+i);
    for(int i=1; i<=N; i++)
        scanf("%d", P+i);
    init();
    while(Q--)
    {
        int t;
        scanf("%d", &t);
        if(t==1)
        {
            int a, b;
            scanf("%d%d", &a, &b);

            int o=P[a];

            rem(o);
            rem(P[o]);
            rem(P[P[o]]);
            S[o].erase(S[o].find(V[a]));
            S[P[o]].erase(S[P[o]].find(V[o]));
            V[o]-=A[a]/(deg[a]+1);
            V[o]-=A[o]-A[o]/(deg[o]+1)*deg[o];
            S[P[P[o]]].erase(S[P[P[o]]].find(V[P[o]]));
            V[P[o]]-=A[o]/(deg[o]+1);
            deg[o]--;
            V[P[o]]+=A[o]/(deg[o]+1);
            S[P[P[o]]].insert(V[P[o]]);
            V[o]+=A[o]-A[o]/(deg[o]+1)*deg[o];
            S[P[o]].insert(V[o]);
            add(P[P[o]]);
            add(P[o]);
            add(o);

            P[a]=b;

            rem(b);
            rem(P[b]);
            rem(P[P[b]]);
            S[P[b]].erase(S[P[b]].find(V[b]));
            V[b]-=A[b]-A[b]/(deg[b]+1)*deg[b];
            S[P[P[b]]].erase(S[P[P[b]]].find(V[P[b]]));
            V[P[b]]-=A[b]/(deg[b]+1);
            deg[b]++;
            V[P[b]]+=A[b]/(deg[b]+1);
            S[P[P[b]]].insert(V[P[b]]);
            V[b]+=A[b]-A[b]/(deg[b]+1)*deg[b];
            V[b]+=A[a]/(deg[a]+1);
            S[P[b]].insert(V[b]);
            S[b].insert(V[a]);
            add(P[P[b]]);
            add(P[b]);
            add(b);
        }
        else if(t==2)
        {
            int a;
            scanf("%d", &a);
            printf("%lld\n", V[a]+A[P[a]]/(deg[P[a]]+1));
        }
        else
            printf("%lld %lld\n", *all.begin(), *all.rbegin());
    }
    return 0;
}