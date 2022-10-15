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

const int MAXN = 100000;

void queries(int A, int B, vector<vector<int>> &vres)
{
    const int N = B-A;
    if (N < 2) return;
    if (N == 2)
    {
        vres.push_back({A});
        vres.push_back({A+1});
        return;
    }
    int mid = N/2;
    vres.emplace_back(mid);
    forn(i,mid) vres.back()[i] = A+i;
    vres.emplace_back(N-mid);
    forsn(i,mid, N) vres.back()[i-mid] = A+i;
    int tope = (int)vres.size();
    queries(A, A+mid,vres);
    vector<vector<int>> aux;
    queries(A+mid, B,aux);
    forn(i,aux.size())
    {
        while (tope+i >= (int)vres.size())
            vres.emplace_back();
        for (int z : aux[i])
            vres[tope+i].push_back(z);
    }
}

const int INF = 1000000000;

int main() 
{
    int _sc = 0;
    int N; _sc = scanf("%d", &N);
    
    vector<vector<int>> qqq;
    queries(0,N, qqq);
        
    vector<int> minimum(N, INF);
    
    for (const auto &q : qqq)
    {
        printf("%d\n", (int)q.size());
        forn(i,q.size())
        {
            if (i) printf(" ");
            printf("%d", q[i]+1);
        }
        printf("\n");
        fflush(stdout);
        
        vector<char> inQuery(N, false);
        for (int z : q) inQuery[z] = true;
        forn(i,N)
        {
            int qret;
            _sc = scanf("%d", &qret);
            if (!inQuery[i])
                minimum[i] = min(minimum[i], qret);
        }
    }
    printf("-1\n");
    forn(i,N)
    {
        if (i) printf(" ");
        printf("%d", minimum[i]);
    }
    printf("\n");
    fflush(stdout);
    if (_sc) return 0;
    return 0;
}