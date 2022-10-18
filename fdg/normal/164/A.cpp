#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

vector <vector <int> > g,gt;
int f[100005];
int q1[100005],q1s=0;
int q2[100005],q2s=0;
bool ok1[100005],ok2[100005];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    g.resize(n); gt.resize(n);
    for(int i=0;i<n;++i) {
        scanf("%d",&f[i]);
        if (f[i]==1) {
            q1[q1s++]=i; ok1[i]=true;
        } else if (f[i]==2) {
            q2[q2s++]=i; ok2[i]=true;
        }
    }
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b);
        --a; --b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    int qh=0;
    while(qh<q1s) {
        int v=q1[qh++];
        for(int i=0;i<g[v].size();++i) {
            if (!ok1[g[v][i]]) {
                ok1[g[v][i]]=true;
                q1[q1s++]=g[v][i];
            }
        }
    }
    qh=0;
    while(qh<q2s) {
        int v=q2[qh++];
        if (f[v]==1) continue;
        for(int i=0;i<gt[v].size();++i) {
            if (!ok2[gt[v][i]]) {
                ok2[gt[v][i]]=true;
                q2[q2s++]=gt[v][i];
            }
        }
    }
    for(int i=0;i<n;++i)
        if (ok1[i]&&ok2[i]) puts("1");
        else puts("0");
    return 0;
}