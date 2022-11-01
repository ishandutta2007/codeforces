#include <bits/stdc++.h>

using namespace std;

int K, N, M;
int A[100001];
int belong[100001];
bool special[100001];
pair<int, int> B[100001];
vector<pair<int, int>> add[100001];
vector<pair<int, int>> mul;
vector<pair<int, int>> adds;
vector<pair<long double, int>> V;
vector<pair<int, int>> addsused;
long double psum[100001];

int main()
{
    scanf("%d%d%d", &K, &N, &M);
    for(int i=1; i<=K; i++)
        scanf("%d", A+i);
    int a, b, c;
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(a==1)
            B[b]=max(B[b], {c-A[b], i}), special[i]=true;
        else if(a==2)
            add[b].push_back({c, i});
        else
            mul.push_back({c, i});
        belong[i]=b;
    }
    sort(mul.rbegin(), mul.rend());
    for(size_t i=0; i<mul.size(); i++)
    {
        if(i>0)
            psum[i]=psum[i-1];
        psum[i]+=logl(mul[i].first);
    }
    for(int i=1; i<=K; i++)
    {
        if(B[i].second)
            add[i].push_back(B[i]);
        sort(add[i].rbegin(), add[i].rend());
        long long sum=A[i];
        for(auto& it: add[i])
        {
            V.push_back({logl(sum+it.first)-logl(sum), it.second});
            sum+=it.first;
        }
    }
    sort(V.rbegin(), V.rend());
    long double sum=0.0;
    long double maxi=mul.empty()?0.0:psum[min(M-1, (int)mul.size()-1)];
    int idx=-1;
    for(size_t i=0; i<V.size(); i++)
    {
        sum+=V[i].first;
        if(-1<=M-(int)i-2 && sum+(mul.empty() || min(M-(int)i-2, (int)mul.size()-1)<0?0.0:psum[min(M-(int)i-2, (int)mul.size()-1)])>maxi)
        {
            maxi=sum+(mul.empty() || min(M-(int)i-2, (int)mul.size()-1)<0?0.0:psum[min(M-(int)i-2, (int)mul.size()-1)]);
            idx=i;
        }
    }
    if(idx==-1)
    {
        if(mul.empty())
            printf("0\n");
        else
        {
            printf("%d\n", min(M, (int)mul.size()));
            for(int i=0; i<min(M, (int)mul.size()); i++)
                printf("%d ", mul[i].second);
            printf("\n");
        }
    }
    else
    {
        for(int i=0; i<=idx; i++)
            addsused.push_back({special[V[i].second], V[i].second});
        int mulsused=min(M-idx-1, (int)mul.size());
        printf("%d\n", addsused.size()+mulsused);
        sort(addsused.rbegin(), addsused.rend());
        for(size_t i=0; i<addsused.size(); i++)
            printf("%d ", addsused[i].second);
        for(int i=0; i<mulsused; i++)
            printf("%d ", mul[i].second);
        printf("\n");
    }
    return 0;
}