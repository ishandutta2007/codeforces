#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;

typedef pair<int,int> Edge;
#define cost first
#define pos second

int main() 
{
    #ifdef ACMTUYO
        if (!freopen("b.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N,M;
    while (scanf("%d%d", &N, &M) != EOF)
    {
        vector<Edge> tree, others;
        tree.reserve(N);
        others.reserve(M);
        forn(i,M)
        {
            Edge e; e.pos = i;
            int isTree;
            _sc = scanf("%d%d", &e.cost, &isTree);
            if (isTree) tree.push_back(e);
            else others.push_back(e);
        }
        sort(tree.begin(), tree.end());
        sort(others.begin(), others.end());
        //map<int, int> options;
        //forn(i,N-1)
        //    options[tree[i].cost] += i;
        vector<pair<int,int> > sol(M);
        vector<int> nextOption(N-1);
        forsn(i,1,N-1) nextOption[i] = i-1;
        int it = 1;
        int next = 0;
        while (next < (int)others.size() && it < N-1 && tree[it].cost <= others[next].cost)
        {
            sol[others[next].pos].first = it+2;
            sol[others[next].pos].second = nextOption[it]+1;
            next++;
            if (--nextOption[it] < 0)
                it++;
        }
        if (next == (int)others.size())
        {
            forn(i,N-1)
            {
                sol[tree[i].pos].first = i+1;
                sol[tree[i].pos].second = i+2;
            }
            forn(i,M)
                printf("%d %d\n", sol[i].first, sol[i].second);
        }
        else
            printf("-1\n");
    }
    if (_sc) return 0;
    return 0;
}