#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

const int MOD=51123987;
const int DIV2=(51123987+1)/2;

template<class Key, class Mapped>
struct bad_map
{
    vector<pair<Key, Mapped>> data;
    void clear()
    {
        data.clear();
    }
    Mapped& operator[] (Key k)
    {
        for(size_t i=0; i<data.size(); i++)
            if(data[i].first==k)
                return data[i].second;
        data.push_back(make_pair(k, Mapped()));
        return data.back().second;
    }
};

struct node
{
    int len, sz;
    node *fail;
    bad_map<char, node*> link;
} pool[2000010], *nextpool=pool;

node* alloc()
{
    nextpool->link.clear();
    return nextpool++;
}

int N;
char S[2000002];
int L[2000002], R[2000002];

void buildA(int A[])
{
    nextpool=pool;
    node *root=alloc();
    root->len=-1;
    root->sz=0;
    node *zero=alloc();
    zero->len=0;
    zero->sz=0;
    zero->fail=root;
    node *cur=root;
    for(int i=1; i<=N; i++)
    {
        while(S[i-cur->len-1]!=S[i])
            cur=cur->fail;
        node*& nxt=cur->link[S[i]];
        if(!nxt)
        {
            nxt=alloc();
            nxt->len=cur->len+2;
            if(nxt->len==1)
                nxt->fail=zero;
            else
            {
                node *fail=cur->fail;
                while(S[i-fail->len-1]!=S[i])
                    fail=fail->fail;
                nxt->fail=fail->link[S[i]];
            }
            nxt->sz=nxt->fail->sz+1;
        }
        cur=nxt;
        A[i]=cur->sz;
    }
}

int main()
{
    scanf("%d", &N);
    scanf("%s", S+1);
    buildA(R);
    reverse(S+1, S+1+N);
    buildA(L);
    reverse(L+1, L+1+N);
    long long ans=0, sum=0;
    for(int i=1; i<=N; i++)
    {
        sum=(sum+L[i])%MOD;
        ans=(ans+sum*R[i]%MOD)%MOD;
    }
    sum=0;
    for(int i=1; i<=N; i++)
    {
        ans=(ans-sum*L[i]%MOD+MOD)%MOD;
        sum=(sum+R[i])%MOD;
    }
    for(int i=1; i<=N; i++)
        ans=(ans-L[i]+MOD)%MOD;
    ans=(ans*DIV2)%MOD;
    printf("%lld\n", ans);
    return 0;
}