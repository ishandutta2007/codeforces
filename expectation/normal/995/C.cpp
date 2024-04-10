//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
#include <sstream>
#include <string.h>
#include<fstream>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define MP make_pair
#define I insert
#define mod 1000000007
#define INF 1000000001
#define PB push_back
#define x0 sdfhrthrth
#define x1 fdhttrlhn
#define y0 kihrbdb
#define y1 ugvrrtgtrg
#define eps 1e-5
#define X first
#define Y second

int n;
PII V[200000];
vector<int> TO[200000];
int res[200000];
vector<int> G;

bool ok(int i1, int i2, int ind)
{
    PII p1 = V[i1];
    if (ind == 1) p1.first += V[i2].first, p1.second += V[i2].second;
    else p1.first -= V[i2].first, p1.second -= V[i2].second;
    if (p1.first*1LL*p1.first + p1.second*1LL*p1.second <= 1LL*1000*1000*1000*1000) return true;
    return false;
}

bool ok2(int i1, int i2, int ind)
{
    PII p1 = V[i1];
    if (ind == 1) p1.first += V[i2].first, p1.second += V[i2].second;
    else p1.first -= V[i2].first, p1.second -= V[i2].second;
    if (p1.first*1LL*p1.first + p1.second*1LL*p1.second <= 1LL*1500*1000*1000*1000) return true;
    return false;
}

void merge(int to, int from, int ind)
{
    FOR (i,0,TO[from].size()) TO[to].PB(TO[from][i]);
    if (ind == 1) V[to].first += V[from].first, V[to].second += V[from].second;
             else V[to].first -= V[from].first, V[to].second -= V[from].second;
    if (ind == -1)
        FOR (i,0,TO[from].size())
            res[TO[from][i]] *= -1;
}

int main()
{
    cin >> n;
    FOR (i,0,n) cin >> V[i].first >> V[i].second;
    FOR (i,0,n) G.PB(i), res[i] = 1, TO[i].PB(i);
    while (G.size() >= 3)
    {
        int p1 = G.back(); G.pop_back();
        int p2 = G.back(); G.pop_back();
        int p3 = G.back(); G.pop_back();
        
        if (ok(p1,p2,1)) {
            if (TO[p1].size() > TO[p2].size()) merge(p1,p2,1), G.PB(p1);
            else merge(p2,p1,1), G.PB(p2);
            G.PB(p3);
            continue; }
        
        if (ok(p1,p3,1)) {
            if (TO[p1].size() > TO[p3].size()) merge(p1,p3,1), G.PB(p1);
            else merge(p3,p1,1), G.PB(p3);
            G.PB(p2);
            continue; }
        
        if (ok(p2,p3,1)) {
            if (TO[p2].size() > TO[p3].size()) merge(p2,p3,1), G.PB(p2);
            else merge(p3,p2,1), G.PB(p3);
            G.PB(p1);
            continue; }
        
        if (ok(p1,p2,-1)) {
            if (TO[p1].size() > TO[p2].size()) merge(p1,p2,-1), G.PB(p1);
            else merge(p2,p1,-1), G.PB(p2);
            G.PB(p3);
            continue; }
        
        if (ok(p1,p3,-1)) {
            if (TO[p1].size() > TO[p3].size()) merge(p1,p3,-1), G.PB(p1);
            else merge(p3,p1,-1), G.PB(p3);
            G.PB(p2);
            continue; }
        
        if (ok(p2,p3,-1)) {
            if (TO[p2].size() > TO[p3].size()) merge(p2,p3,-1), G.PB(p2);
            else merge(p3,p2,-1), G.PB(p3);
            G.PB(p1);
            continue; }
    }
    
    if (G.size() == 2)
    {
        int p1 = G.back(); G.pop_back();
        int p2 = G.back(); G.pop_back();
        
        if (ok2(p1,p2,1)) {
            if (TO[p1].size() < TO[p2].size()) merge(p1,p2,1), G.PB(p1);
            else merge(p2,p1,1), G.PB(p2); }
        else {
            if (TO[p1].size() < TO[p2].size()) merge(p1,p2,-1), G.PB(p1);
            else merge(p2,p1,-1), G.PB(p2); }
    }
    
    FOR (i,0,n) cout << res[i] << " ";
}