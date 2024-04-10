#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int l[100100],r[100100],pre[1010]={-1};

void kmp(int f[],string s,string t)
{
    int i=0,j=-1,m=sz(s),n=sz(t);
    while (i<n)
    {
        while (j>=0 && t[i]!=t[j]) j=pre[j];
        i++; j++;
        pre[i]=(j>=n || t[i]!=t[j]?j:pre[j]);
    }
    i=j=0;
    while (i<m)
    {
        while (j>=0 && s[i]!=t[j]) j=pre[j];
        f[++i]=++j;
        if (j>=n) j=pre[j];
    }
}

int match(string s,string t)
{
    kmp(l,s,t);
    reverse(all(s));
    reverse(all(t));
    kmp(r,s,t);
    
    int m=sz(s),n=sz(t);
    reverse(r+1,r+m+1);
    
    fr(i,2,m) l[i]=max(l[i],l[i-1]);
    frr(i,m-1,1) r[i]=max(r[i],r[i+1]);
    
    fr(i,1,m-1)
        if (l[i] && r[i+1] && (l[i]<n || r[i+1]<n) && l[i]+r[i+1]>=n) return 1;
    return 0;
}

int main()
{
    int ans=0,m;
    string s,t;
    cin >> s >> m;
    while (m--) cin >> t, ans+=match(s,t);
    cout << ans << endl;
}