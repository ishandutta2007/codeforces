#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

const int maxn = 5 * 100000;

pair<pair<int,int>,int> inv[maxn];
int a[maxn],n,m;
long long s[maxn],f[maxn];

struct Node
{
    int l,r;
    long long maxi,cover;
} tree[maxn*4];

const int root = 1;

void buildTree(int l,int r,int p)
{
    tree[p].l = l;
    tree[p].r = r;
    tree[p].cover = tree[p].maxi = 0;
    int mid = (l+r)>>1;
    if (l < r)
    {
        buildTree(l,mid,p*2),
        buildTree(mid+1,r,p*2+1);
    }
}

void down(int p)
{
    tree[p*2].cover += tree[p].cover;
    tree[p*2+1].cover += tree[p].cover;
    tree[p*2].maxi += tree[p].cover;
    tree[p*2+1].maxi += tree[p].cover;
    tree[p].cover = 0;
}

void up(int p)
{
    tree[p].maxi = max(tree[p*2].maxi,tree[p*2+1].maxi);
}

void add(int l,int r,int p,long long delta)
{
    if (l <= tree[p].l && r >= tree[p].r)
    {
        tree[p].cover += delta;
        tree[p].maxi += delta;
        return;
    }
    down(p);
    int mid = (tree[p].l + tree[p].r)>>1;
    if (l <= mid) add(l,r,p*2,delta);
    if (r > mid) add(l,r,p*2+1,delta);
    up(p);
}

/*
f[i] = max{f[j] + w[j,i] + s[j-1]} - s[i]
*/

int main()
{
    cin >> n >> m;
    s[0] = f[0] = 0;
    REP(i,n) cin >> s[i+1];
    REP(i,n) s[i+1] += s[i];
    REP(i,m) cin >> inv[i].first.second >> inv[i].first.first >> inv[i].second;
    sort(inv,inv+m);
    int now = 0;
    buildTree(0,n+10,root);
    long long ans = 0;
    for (int i = 1;i <= n;++i)
    {
        while (now < m && inv[now].first.first <= i)
        {
            add(0,--inv[now].first.second,root,inv[now].second);
            ++now;
        }
        f[i] = max(f[i-1],tree[root].maxi - s[i]);
        ans = max(ans,f[i]);
     //   cout << "f[i] = " << f[i] << " " << tree[root].maxi << endl;
        add(i,i,root,f[i]+s[i]);
    }
    cout << ans << endl;


    return 0;
}