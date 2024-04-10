#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>

using namespace std;

vector < vector <int> > v,g;

int st[5002]={0},top=-1,deg[102]={0},n,m,deg1[102]={0};
vector <int> res;
int D[101][101]={0};

void build_euler(int start)
{
    st[++top]=start;
    while(top!=-1)
    {
        if (deg[st[top]]==0)
            res.push_back(st[top--]);
        else
        {
            int next=0;
//          for(int i=0;i<v[st[top]].size();i++)
//              if (v[st[top]][next]>v[st[top]][i]) next=i;
            st[top+1]=v[st[top]][next];
            deg[st[top]]--;
            deg[v[st[top]][next]]--;
            for(int i=0;i<v[v[st[top]][next]].size();i++)
                if (v[v[st[top]][next]][i]==st[top])
                {
                    v[v[st[top]][next]].erase(v[v[st[top]][next]].begin()+i);
                    break;
                }
            v[st[top]].erase(v[st[top]].begin()+next);
            top++;
        }
    }
}

vector <int> path;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    scanf("%d%d",&n,&m);
    g.resize(n);
    path.resize(m+1);
    for(int i=0;i<=m;i++)
    {
        scanf("%d",&path[i]);
        path[i]--;
    }
    path.pop_back();
    g[path[0]].push_back(path.back());
    g[path.back()].push_back(path[0]);
    D[path[0]][path.back()]++;
    D[path.back()][path[0]]++;
    deg1[path[0]]++; deg1[path.back()]++;
    int kol=2,last1=-1;
    bool finded=false;
    for(int i=path.size()-1;i>0;i--)
    {
        if (finded) break;
        g[path.back()].push_back(path[path.size()-2]);
        g[path[path.size()-2]].push_back(path.back());
        deg1[path[path.size()-2]]++; deg1[path.back()]++;
        D[path[path.size()-2]][path.back()]++;
        D[path.back()][path[path.size()-2]]++;
        int last=path[i];
        path.pop_back();
        for(int t=last+1;t<=n;t++)
        {
            if (D[path[i-1]][t])
            {
                memcpy(deg,deg1,sizeof(deg));
                deg[path[i-1]]--; deg[t]--;
                v=g;
                for(int j=0;j<v[t].size();j++)
                    if (v[t][j]==path[i-1])
                    {
                        v[t].erase(v[t].begin()+j);
                        break;
                    }
                for(int j=0;j<v[path[i-1]].size();j++)
                    if (v[path[i-1]][j]==t)
                    {
                        v[path[i-1]].erase(v[path[i-1]].begin()+j);
                        break;
                    }
                res.clear();
                build_euler(t);
                if (res.size()==kol&&res[0]==path[0])
                {
                    last1=t;
                    deg1[t]--; deg1[path[i-1]]--;
                    D[path[i-1]][t]--;
                    D[t][path[i-1]]--;
                    for(int j=0;j<g[t].size();j++)
                        if (g[t][j]==path[i-1])
                        {
                            g[t].erase(g[t].begin()+j);
                            break;
                        }
                    for(int j=0;j<g[path[i-1]].size();j++)
                        if (g[path[i-1]][j]==t)
                        {
                            g[path[i-1]].erase(g[path[i-1]].begin()+j);
                            break;
                        }
                    path.push_back(t);
                    //for(int j=res.size()-1;j>=0;j--)
                    //  cout << " " << res[j]+1;
                    //cout << endl;
                    finded=true;
                    break;
                }
            }
        }
        kol++;
    }
    if (!finded) cout << "No solution\n";
    else
    {
        while(path.size()<=m)
        {
            for(int t=0;t<n;t++)
            {
                if (D[last1][t])
                {
                    memcpy(deg,deg1,sizeof(deg));
                    deg[last1]--; deg[t]--;
                    v=g;
                    for(int j=0;j<v[last1].size();j++)
                        if (v[last1][j]==t)
                        {
                            v[last1].erase(v[last1].begin()+j);
                            break;
                        }
                    for(int j=0;j<v[t].size();j++)
                        if (v[t][j]==last1)
                        {
                            v[t].erase(v[t].begin()+j);
                            break;
                        }
                    res.clear();
                    build_euler(t);
                    if (res.size()==m+1-path.size())
                    {
                        D[last1][t]--; D[t][last1]--;
                        path.push_back(t);
                        deg1[last1]--; deg1[t]--;
                        for(int j=0;j<g[last1].size();j++)
                            if (g[last1][j]==t)
                            {
                                g[last1].erase(g[last1].begin()+j);
                                break;
                            }
                        for(int j=0;j<g[t].size();j++)
                            if (g[t][j]==last1)
                            {
                                g[t].erase(g[t].begin()+j);
                                break;
                            }
                        last1=t;
                        break;
                    }
                }
            }
        }
        cout << path[0]+1;
        for(int i=1;i<path.size();i++)
            cout << " " << path[i]+1;
        cout << endl;
    }
    return 0;
}