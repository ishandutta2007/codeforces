#include <bits/stdc++.h>

using namespace std;

const int LT=0;
const int GT=1;
const int LE=2;
const int GE=3;
const int EQ=4;
int N, K;
vector<pair<int, int>> req[71];
long long dp[71][71];

long long solve(int l, int r)
{
    if(l==1 && r==2*N)
        return 1;
    long long& ret=dp[l][r];
    if(ret!=-1)
        return ret;
    ret=0;
    if(l-2>=1 && l<=r)
    {
        for(int i=0; i<2; i++)
        {
            for(auto& it: req[l-1-i])
            {
                if(it.second==EQ)
                {
                    if(!(it.first==l-2 || it.first==l-1))
                        goto rr;
                }
                else if(it.second==GT)
                {
                    if(!(it.first>r || it.first<l-2))
                        goto rr;
                }
                else if(it.second==GE)
                {
                    if(!(it.first>r || it.first<l))
                        goto rr;
                }
                else if(it.second==LT)
                {
                    if(!(l<=it.first && it.first<=r))
                        goto rr;
                }
                else if(it.second==LE)
                {
                    if(!(l-2<=it.first && it.first<=r))
                        goto rr;
                }
            }
        }
        ret+=solve(l-2, r);
    }
    rr:;
    if(r+2<=2*N && l<=r)
    {
        for(int i=0; i<2; i++)
        {
            for(auto& it: req[r+1+i])
            {
                if(it.second==EQ)
                {
                    if(!(it.first==r+1 || it.first==r+2))
                        goto lr;
                }
                else if(it.second==GT)
                {
                    if(!(it.first>r+2 || it.first<l))
                        goto lr;
                }
                else if(it.second==GE)
                {
                    if(!(it.first>r || it.first<l))
                        goto lr;
                }
                else if(it.second==LT)
                {
                    if(!(l<=it.first && it.first<=r))
                        goto lr;
                }
                else if(it.second==LE)
                {
                    if(!(l<=it.first && it.first<=r+2))
                        goto lr;
                }
            }
        }
        ret+=solve(l, r+2);
    }
    lr:;
    if(l-1>=1 && r+1<=2*N)
    {
        for(int i=0; i<2; i++)
        {
            int x=l-1, y=r+1;
            if(i)
                swap(x, y);
            for(auto& it: req[x])
            {
                if(it.second==EQ)
                {
                    if(!(it.first==x || it.first==y))
                        goto bad;
                }
                else if(it.second==GT)
                {
                    if(!(it.first<l-1 || it.first>r+1))
                        goto bad;
                }
                else if(it.second==GE)
                {
                    if(!(it.first<l || it.first>r))
                        goto bad;
                }
                else if(it.second==LT)
                {
                    if(!(it.first>=l && it.first<=r))
                        goto bad;
                }
                else if(it.second==LE)
                {
                    if(!(it.first>=l-1 && it.first<=r+1))
                        goto bad;
                }
            }
        }
        ret+=solve(l-1, r+1);
    }
    bad:;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d%d", &N, &K);
    int a, b;
    char op[10];
    for(int i=0; i<K; i++)
    {
        scanf("%d%s%d", &a, op, &b);
        if(strlen(op)==1)
        {
            if(*op=='=')
            {
                req[a].push_back({b, EQ});
                req[b].push_back({a, EQ});
            }
            else if(*op=='<')
            {
                req[a].push_back({b, LT});
                req[b].push_back({a, GT});
            }
            else
            {
                req[a].push_back({b, GT});
                req[b].push_back({a, LT});
            }
        }
        else if(*op=='<')
        {
            req[a].push_back({b, LE});
            req[b].push_back({a, GE});
        }
        else
        {
            req[a].push_back({b, GE});
            req[b].push_back({a, LE});
        }
    }
    long long ans=0;
    for(int i=1; i<2*N; i++)
        ans+=solve(i+1, i);
    printf("%lld\n", ans);
    return 0;
}