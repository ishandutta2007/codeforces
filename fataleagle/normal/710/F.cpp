#include <bits/stdc++.h>

using namespace std;

struct AC
{
    vector<string> keys;
    vector<map<char, int>> trie;
    vector<long long> endp;
    vector<int> fail;
    AC()
    {
        trie.resize(1);
        endp.resize(1);
    }
    void reset()
    {
        keys.clear();
        trie.clear();
        endp.clear();
        fail.clear();
        trie.resize(1);
        endp.resize(1);
    }
    void add_string(string& s)
    {
        keys.push_back(s);
        int cur=0;
        for(int i=0; i<(int)s.length(); i++)
        {
            if(trie[cur].count(s[i]))
                cur=trie[cur][s[i]];
            else
            {
                cur=trie[cur][s[i]]=trie.size();
                trie.push_back(map<char, int>());
                endp.push_back(0);
            }
        }
        endp[cur]++;
    }
    void build()
    {
        fail.resize(trie.size());
        vector<pair<int, pair<int, char>>> Q;
        Q.push_back({0, {0, '\0'}});
        fail[0]=0;
        for(int i=0; i<(int)Q.size(); i++)
        {
            int u=Q[i].first;
            int p=Q[i].second.first;
            char c=Q[i].second.second;
            for(auto& it: trie[u])
                Q.push_back({it.second, {u, it.first}});
            if(u==0)
                continue;
            int f=fail[p];
            while(f!=0 && !trie[f].count(c))
                f=fail[f];
            if(!trie[f].count(c) || trie[f][c]==u)
                fail[u]=0;
            else
                fail[u]=trie[f][c];
            endp[u]+=endp[fail[u]];
        }
    }
    long long count(string& s)
    {
        if(keys.empty())
            return 0;
        long long ret=0;
        int cur=0;
        for(int i=0; i<(int)s.length(); i++)
        {
            while(cur!=0 && !trie[cur].count(s[i]))
                cur=fail[cur];
            if(trie[cur].count(s[i]))
                cur=trie[cur][s[i]];
            ret+=endp[cur];
        }
        return ret;
    }
};

struct StaticToDynamic
{
    AC ac[19];
    void add(string& s)
    {
        int k=0;
        for(int i=0; i<19; i++) if(ac[i].keys.empty())
        {
            k=i;
            break;
        }
        ac[k].add_string(s);
        for(int i=0; i<k; i++)
        {
            for(auto& it: ac[i].keys)
                ac[k].add_string(it);
            ac[i].reset();
        }
        ac[k].build();
    }
    long long count(string& s)
    {
        long long ret=0;
        for(int i=0; i<19; i++)
            ret+=ac[i].count(s);
        return ret;
    }
} r, g;

char buf[300001];

int main()
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        int t;
        scanf("%d%s", &t, buf);
        string s(buf, buf+strlen(buf));
        if(t==1)
            r.add(s);
        else if(t==2)
            g.add(s);
        else
        {
            printf("%I64d\n", r.count(s)-g.count(s));
            fflush(stdout);
        }
    }
    return 0;
}