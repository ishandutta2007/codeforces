#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

char *s[100005];
char str[300005];
vector < vector <int> > g;
int p[300005],ans=0,ln;

inline void dfs(int v,int pref) {
    int l=strlen(s[v]);
    for(int i=0;i<l;++i) {
        while(pref>0&&s[v][i]!=str[pref]) pref=p[pref-1];
        if (s[v][i]==str[pref]) ++pref;
        if (pref==ln) {
            ans++;
            pref=p[pref-1];
        }
    }
    for(int i=0;i<g[v].size();++i)
        dfs(g[v][i],pref);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    g.clear(); g.resize(n);
    for(int i=1;i<n;++i) {
        int a;
        scanf("%d %s",&a,str); --a;
        g[a].push_back(i);
        int l=strlen(str);
        s[i]=new char[l+1];
        memcpy(s[i],str,l+1);
    }
    scanf("%s",str);
    int pref=0,l=strlen(str); ln=l;
    for(int i=1;i<l;++i) {
        while(pref>0&&str[i]!=str[pref]) pref=p[pref-1];
        if (str[i]==str[pref]) ++pref;
        p[i]=pref;
    }
    for(int i=0;i<g[0].size();++i)
        dfs(g[0][i],0);
    printf("%d\n",ans);
    return 0;
}