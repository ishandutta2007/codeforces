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
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

int max(int a,int b) {return a>b?a:b;}
int abs(int x) {return x<0?-x:x;}



    int t;
    string s,a[50],b[50];
    int A,B,C;
    int x,y,z,mi = 0x7fffffff,last = 0;
    int XX[10];
    map<string,int> hash;
    int mp[10][10];
    int bel[10][10];
    int sum[10];
    int ret = 0;

void dfs(int ix)
{
    if (ix == 7)
    {
                if (!sum[0] || !sum[1] || !sum[2]) return;
        int i,j,k;
        i = sum[0]; j = sum[1]; k = sum[2];
        int pp = max(abs(A/i-B/j),max(abs(A/i-C/k),abs(C/k-B/j)));
        if (pp == mi)
            {
                int best = 0;
                for (int l = 0;l < 3;++l)
                {
                    int ans = 0;
                    for (int p = 0;p < sum[l];++p)
                        for (int q = 0;q < sum[l];++q)
                            ans += mp[bel[l][p]][bel[l][q]];
                    best += ans;
                }
                    ret = max(ret,best);
            }
        return;
    }
    REP(xx,3)
    {
        bel[xx][sum[xx]++] = ix;
        dfs(ix+1);
        --sum[xx];
    }
}

int main()
{
    cin >> t;
    CLEAR(mp);
    CLEAR(sum);
    last = 0;
    REP(i,t)
    {
        cin >> a[i] >> s >> b[i];
        if (hash.find(a[i]) == hash.end())
            hash[a[i]] = last++;
        if (hash.find(b[i]) == hash.end())
            hash[b[i]] = last++;
        mp[hash[a[i]]][hash[b[i]]] += 1;
    }
    cin >> A >> B >> C;
    REP (i,8)
        REP(j,8)
            REP(k,8)
                if (i&&j&&k && i+j+k == 7)
                    if (max(abs(A/i-B/j),max(abs(A/i-C/k),abs(C/k-B/j))) < mi)
                    {
                        mi = max(abs(A/i-B/j),max(abs(A/i-C/k),abs(C/k-B/j)));
                    }
    dfs(0);
    cout << mi << " " << ret << endl;
    return 0;
}