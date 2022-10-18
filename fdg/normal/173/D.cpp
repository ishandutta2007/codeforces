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

vector < vector <int> > g;
int color[100002],ans[100002];
bool was[100002];

void dfs(int v,int col = 0) {
    color[v]=col+1;
    for(int i=0;i<g[v].size();++i)
        if (!color[g[v][i]]) dfs(g[v][i],col^1);
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    g.resize(n);
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;++i)
        if (!color[i]) dfs(i);
    int cnt[2]={0};
    for(int i=0;i<n;++i)
        cnt[color[i]-1]++;
    if (cnt[0]%3==2) {
        swap(cnt[0],cnt[1]);
        for(int i=0;i<n;++i)
            if (color[i]==1) color[i]=2;
            else color[i]=1;
    }
    bool ok=false;
    int last=0;
    if (cnt[0]%3==1) {
        for(int i=0;i<n;++i) {
            if (color[i]==1&&cnt[1]-g[i].size()>=2) {
                ok=true;
                ++last;
                for(int j=0;j<g[i].size();++j)
                    was[g[i][j]]=true;
                int left=2;
                ans[i]=last;
                for(int j=0;j<n&&left;++j) {
                    if (color[j]==2&&!was[j]) {
                        ans[j]=last; --left;
                    }
                }
                break;
            }
        }
        if (!ok) {
            int found=2;
            for(int i=0;i<n&&found;++i) {
                if (color[i]==2&&cnt[0]-g[i].size()>=2) {
                    ++last; --found;
                    memset(was,false,sizeof(was));
                    for(int j=0;j<g[i].size();++j)
                        was[g[i][j]]=true;
                    int left=2;
                    ans[i]=last;
                    for(int j=0;j<n&&left;++j) {
                        if (color[j]==1&&!was[j]) {
                            ans[j]=last; --left;
                        }
                    }
                }
            }
            ok=found==0;
        }
    } else ok=true;
    if (!ok) printf("NO\n");
    else {
        int left=3;
        for(int i=0;i<n;++i) {
            if (!ans[i]&&color[i]==1) {
                if (left==3) ++last;
                ans[i]=last; --left;
                if (left==0) left=3;
            }
        }
        for(int i=0;i<n;++i) {
            if (!ans[i]&&color[i]==2) {
                if (left==3) ++last;
                ans[i]=last; --left;
                if (left==0) left=3;
            }
        }
        printf("YES\n");
        for(int i=0;i<n;++i) {
            if (i) printf(" ");
            printf("%d",ans[i]);
        }
    }
    return 0;
}