#include <bits/stdc++.h>

using namespace std;

struct node
{
    string s;
    vector<node*> adj;
    int depth()
    {
        int d=0;
        for(auto& n: adj)
            d=max(d, 1+n->depth());
        return d;
    }
};

int N;
char S[1000001];

pair<string, int> get_token(int pos)
{
    int p=pos;
    for(; p<N && S[p]!=','; p++);
    return make_pair(string(S+pos, S+p), p);
}

pair<node*, int> parse(int pos)
{
    node *ret=new node();
    int p, p2, n;
    tie(ret->s, p)=get_token(pos);
    string ns;
    tie(ns, p2)=get_token(p+1);
    stringstream ss(ns);
    ss>>n;
    for(int i=0; i<n; i++)
    {
        node *ch;
        tie(ch, p)=parse(p2+1);
        ret->adj.push_back(ch);
        p2=p;
    }
    return make_pair(ret, p2);
}

int main()
{
    scanf("%s", S);
    N=strlen(S);
    node *tree=new node();
    int pos=0;
    while(pos<N)
    {
        node *ch;
        int p;
        tie(ch, p)=parse(pos);
        tree->adj.push_back(ch);
        pos=p+1;
    }
    printf("%d\n", tree->depth());
    queue<node*> Q;
    Q.push(tree);
    bool first=true;
    while(!Q.empty())
    {
        int temp=Q.size();
        while(temp--)
        {
            node *u=Q.front();
            Q.pop();
            if(!u->s.empty())
                printf("%s ", u->s.c_str());
            for(auto& v: u->adj)
                Q.push(v);
        }
        if(!first)
            printf("\n");
        first=false;
    }
    return 0;
}