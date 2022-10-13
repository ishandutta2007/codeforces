#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;

int n,m,d[1010],e[1010],S,M;
pair<int,int> edge[100100];
string whose[100100];
vector <int> ans;

int get(int d[],int x)
{
    return (d[x]-x?d[x]=get(d,d[x]):x);
}

int main()
{
    string s;
    cin >> n >> m;
    for (int i=0;i<m;i++) cin >> edge[i].first >> edge[i].second >> whose[i];
    for (int i=1;i<=n;i++) d[i]=e[i]=i;
    
    // keep all S
    for (int i=0;i<m;i++)
        if (whose[i]=="S")
        {
            int x=get(d,edge[i].first),y=get(d,edge[i].second);
            if (x-y) ++S, d[x]=y;
        }
    if (S*2<n-1 || n%2==0) 
    {
        puts("-1"); return 0;
    }
    
    // must have M
    for (int i=0;i<m;i++)
        if (whose[i]=="M")
        {
            int x=get(d,edge[i].first),y=get(d,edge[i].second);
            if (x-y) 
            {
                ans.push_back(i);
                d[x]=y; ++M;
                e[get(e,edge[i].first)]=get(e,edge[i].second);
            }
        }
    
    // fulfill M
    for (int i=0;i<m && M<(n-1)/2;i++)
        if (whose[i]=="M")
        {
            int x=get(e,edge[i].first),y=get(e,edge[i].second);
            if (x-y) ans.push_back(i), ++M, e[x]=y;
        }
    if (M<(n-1)/2)
    {
        puts("-1"); return 0;
    }   
        
    // the rest S
    for (int i=0;i<m;i++)
        if (whose[i]=="S")
        {
            int x=get(e,edge[i].first),y=get(e,edge[i].second);
            if (x-y) ans.push_back(i), e[x]=y;
        }
    
    if (ans.size()<n-1)
    {
        puts("-1"); return 0;
    }
    
    cout << n-1 << endl;
    for (int i=0;i<n-1;i++) cout << ans[i]+1 << ' ';
}