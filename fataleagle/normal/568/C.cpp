#include <bits/stdc++.h>

using namespace std;

int N, M, R;
char VC[201];
int S[201];
char T[201];
bool done[201];
bool done2[201];
vector<pair<pair<int, char>, pair<int, char>>> rules, rulesb[201], rulese[201];
int mask[201];
int mask2[201];
int smallv, smallc;

int id(char c)
{
    return c=='V'?1:2;
}

bool validate()
{
    for(int i=0; i<R; i++)
    {
        int a=rules[i].first.first;
        char b=rules[i].first.second;
        int c=rules[i].second.first;
        char d=rules[i].second.second;
        if(VC[S[a]]==b && VC[S[c]]!=d)
            return false;
    }
    return true;
}

void answer()
{
    for(int i=0; i<N; i++)
        putchar(S[i]+'a');
    putchar('\n');
    exit(0);
}

int nid;
int m[201];
vector<int> adj[500];
int idx[500], low[500], now;
int comp[500], ncomp;
bool onS[500];
vector<int> STK;

void dfs(int u)
{
    idx[u]=low[u]=++now;
    STK.push_back(u);
    onS[u]=true;
    for(auto& v: adj[u])
    {
        if(!idx[v])
        {
            dfs(v);
            low[u]=min(low[u], low[v]);
        }
        else if(onS[v])
            low[u]=min(low[u], idx[v]);
    }
    if(idx[u]==low[u])
    {
        ncomp++;
        int n;
        do
        {
            n=STK.back();
            onS[n]=false;
            STK.pop_back();
            comp[n]=ncomp;
        }
        while(n!=u);
    }
}

bool satisfy(int i)
{
    nid=0;
    for(int j=i+1; j<N; j++)
    {
        if(!done[j])
            m[j]=nid++;
        else
            m[j]=-1;
    }
    for(int j=0; j<nid*2; j++)
        adj[j].clear(), idx[j]=0;
    for(auto& it: rules)
    {
        int a=it.first.first;
        char b=it.first.second;
        int c=it.second.first;
        char d=it.second.second;
        if(a>i && c>i && m[a]!=-1 && m[c]!=-1)
        {
            int x=m[a]*2, y=m[c]*2;
            if(b=='C')
                x++;
            if(d=='C')
                y++;
            adj[x].push_back(y);
        }
    }
    STK.clear();
    ncomp=0;
    now=0;
    for(int j=0; j<nid*2; j++) if(!idx[j])
        dfs(j);
    for(int j=0; j<nid; j++) if(comp[j*2]==comp[j*2+1])
        return false;
    return true;
}

void update(int i, int j)
{
    for(auto& it: rulesb[j])
    {
        int a=it.first.first;
        char b=it.first.second;
        int c=it.second.first;
        char d=it.second.second;
        if(c>i && VC[S[j]]==b)
            mask[c]&=id(d);
    }
    for(auto& it: rulese[j])
    {
        int a=it.first.first;
        char b=it.first.second;
        int c=it.second.first;
        char d=it.second.second;
        if(a>i && VC[S[j]]!=d)
            mask[a]&=3-id(b);
    }
}

bool changeloop(int i)
{
    while(1)
    {
        bool changed=false;
        for(int j=i+1; j<N; j++) if(!done[j])
        {
            if(mask[j]==0)
                return false;
            if(mask[j]<3)
            {
                done[j]=true;
                if(mask[j]==1)
                    S[j]=smallv;
                else
                    S[j]=smallc;
                update(i, j);
                changed=true;
            }
        }
        if(!changed)
            break;
    }
    return true;
}

int main()
{
    scanf("%s", VC);
    M=strlen(VC);
    for(int i=M-1; i>=0; i--)
    {
        if(VC[i]=='V')
            smallv=i;
        else
            smallc=i;
    }
    scanf("%d%d", &N, &R);
    int a, b;
    char c, d;
    for(int i=0; i<R; i++)
    {
        scanf("%d %c%d %c", &a, &c, &b, &d);
        a--, b--;
        rules.push_back({{a, c}, {b, d}});
        rulesb[a].push_back({{a, c}, {b, d}});
        rulese[b].push_back({{a, c}, {b, d}});
    }
    scanf("%s", T);
    for(int i=0; i<N; i++)
        S[i]=T[i]-'a';
    if(validate())
        answer();
    for(int i=N-1; i>=0; i--)
    {
        set<char> seen;
        for(S[i]++; S[i]<M; S[i]++)
        {
            if(seen.count(VC[S[i]]))
                continue;
            seen.insert(VC[S[i]]);
            for(int j=i+1; j<N; j++)
                mask[j]=3;
            for(int j=0; j<R; j++)
            {
                int a=rules[j].first.first;
                char b=rules[j].first.second;
                int c=rules[j].second.first;
                char d=rules[j].second.second;
                if(a<=i && c>i)
                {
                    if(VC[S[a]]==b)
                        mask[c]&=id(d);
                }
                if(a>i && c<=i)
                {
                    if(VC[S[c]]!=d)
                        mask[a]&=3-id(b);
                }
            }
            for(int j=i+1; j<N; j++)
                done[j]=false;
            if(!changeloop(i))
                goto fail;
            if(!satisfy(i))
                goto fail;
            for(int j=i+1; j<N; j++) if(!done[j])
            {
                done[j]=true;
                memcpy(mask2, mask, sizeof mask2);
                memcpy(done2, done, sizeof done2);
                S[j]=min(smallc, smallv);
                update(i, j);
                bool zz=!changeloop(i);
                bool zzz=!satisfy(i);
                if(zz || zzz)
                {
                    memcpy(mask, mask2, sizeof mask);
                    memcpy(done, done2, sizeof done);
                    S[j]=max(smallc, smallv);
                    update(i, j);
                    changeloop(i);
                }
            }
            if(validate())
                answer();
            fail:;
        }
    }
    printf("-1\n");
    return 0;
}