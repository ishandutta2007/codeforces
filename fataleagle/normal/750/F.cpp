#include <bits/stdc++.h>

using namespace std;

int HH, NN;
int P[128];
int I[128];

void gen(int h)
{
    HH=h;
    NN=1<<h;
    NN--;
    for(int i=1; i<=NN; i++)
        P[i]=i;
    random_shuffle(P+1, P+1+NN);
    for(int i=1; i<=NN; i++)
        I[P[i]]=i;
}

int H;
map<int, vector<int>> cache;
set<int> nq;

vector<int> _query(int x)
{
    assert(1<=x && x<=NN);
    nq.insert(x);
    x=I[x];
    if(x==1)
        return {P[2], P[3]};
    if(x*2>NN)
        return {P[x/2]};
    return {P[x/2], P[x*2], P[x*2+1]};
}

vector<int> query(int x)
{
    if(cache.count(x))
        return cache[x];
    if(cache.size()==16)
        return {0, 0};
    printf("? %d\n", x);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    if(k==0)
        exit(0);
    vector<int> ans(k);
    for(int i=0; i<k; i++)
        scanf("%d", &ans[i]);
    return cache[x]=ans;
}

int solve_with_p(int u, int lv, int p)
{
    assert(lv!=1);
    if(lv==2)
        return p;
    if(lv==3)
    {
        auto w=query(p);
        if(w.size()==2)
            return p;
        for(auto& it: w) if(it!=u)
        {
            if(query(it).size()==2)
                return it;
        }
        assert(0);
    }
    if(lv==4)
    {
        auto w=query(p);
        if(w.size()==2)
            return p;
        // lv 2
        for(auto& it: w) if(it!=u)
        {
            auto w2=query(it);
            if(w2.size()==2)
                return it;
            // lv 1
            for(auto& it2: w2) if(it2!=p)
            {
                if(query(it2).size()==2)
                    return it2;
            }
        }
        assert(0);
    }
    int t=H-lv;
    auto w=query(p);
    if(w.size()==2)
        return p;
    w.erase(find(w.begin(), w.end(), u));
    //assert(w.size()==2);
    int v=w[0];
    int g=p;
    for(int i=0; i<t; i++)
    {
        auto w2=query(v);
        if(w2.size()==2)
            return v;
        for(auto& it: w2) if(it!=g)
        {
            g=v;
            v=it;
            break;
        }
    }
    if(query(v).size()==1)
        return solve_with_p(p, lv-1, w[1]);
    return solve_with_p(p, lv-1, w[0]);
}

#define ANSWER(x) do {/*assert(I[x]==1); assert(nq.size()<=16);*/ \
    int ans=x; printf("! %d\n", ans); fflush(stdout); return;} while(0)

void _main()
{
    //H=HH;
    scanf("%d", &H);
    if(H==0)
        exit(0);
    int root=1;
    //root=rand()%((1<<H)-1)+1;
    deque<pair<int, vector<int>>> dq;
    dq.push_back({root, query(root)});
    if(dq.front().second.size()==2)
        ANSWER(root);
    if(dq.front().second.size()==1)
        ANSWER(solve_with_p(root, H, dq.front().second[0]));
    int u=dq.front().second[0];
    int v=dq.front().second[1];
    set<int> seen;
    seen.insert(root);
    while(1)
    {
        seen.insert(u);
        auto w=query(u);
        dq.push_back({u, w});
        if(w.size()==1)
            break;
        if(w.size()==2)
            ANSWER(u);
        for(auto& it: w) if(!seen.count(it))
        {
            u=it;
            break;
        }
    }
    while(1)
    {
        seen.insert(v);
        auto w=query(v);
        dq.push_front({v, w});
        if(w.size()==1)
            break;
        if(w.size()==2)
            ANSWER(v);
        for(auto& it: w) if(!seen.count(it))
        {
            v=it;
            break;
        }
    }
    assert(dq.size()%2==1);
    int n=dq.size();
    auto w=dq[n/2].second;
    set<int> path;
    for(int i=0; i<n; i++)
        path.insert(dq[i].first);
    int x=-1;
    for(auto& it: w) if(!path.count(it))
    {
        assert(x==-1);
        x=it;
    }
    assert(x!=-1);
    ANSWER(solve_with_p(dq[n/2].first, H-n/2, x));
}

#include <random>
std::default_random_engine random_engine(0xdeadbeef);
template<class T>
inline T randint(T L, T R) { return std::uniform_int_distribution<T>(L, R)(random_engine); }

int main()
{
    //freopen("out.txt", "w", stdout);
    int T;
    //T=10000000;
    scanf("%d", &T);
    //srand(time(NULL));
    while(T--)
    {
        //gen(randint(2, 7));
        cache.clear();
        //nq.clear();
        _main();
        /*
        if(nq.size()>=12)
            printf("%d\n", (int)nq.size());
        */
    }
    return 0;
}