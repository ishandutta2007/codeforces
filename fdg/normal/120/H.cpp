#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <memory.h>
#include <string>
#include <map>
#include <set>
#include <ctime>

using namespace std;

int MaxN=202,MAX=200002;

vector <int> gTb(MAX,-1); //NumG
vector < vector <int> > D(MaxN); // NumB*NumG
int k; // startB
vector <int> ColorsB(MaxN,-1); // NumB;


string ans[202];

vector < string > v;
map <string,int> f;

int bc(int x)
{
    int r=0;
    while(x)
    {
        r+=x&1;
        x>>=1;
    }
    return r;
}

void add(string s,int index)
{
    for(int mask=1;mask<(1<<s.size());mask++)
    {
        if (bc(mask)<=4)
        {
            string str="";
            for(int i=0;i<s.size();i++)
                if (mask&(1<<i)) str+=s[i];
            if (!f.count(str))
            {
                v.push_back(str);
                f[str]=v.size()-1;
            }
            D[index].push_back(f[str]);
            
        }
    }
}

int dfs(int b)
{
    if (ColorsB[b]!=k)
    {
        ColorsB[b]=k;
        for(int j=0;j<D[b].size();j++)
        {
            if (gTb[D[b][j]]==-1||dfs(gTb[D[b][j]]))
            {
                gTb[D[b][j]]=b;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    srand(clock());
    int n;
    cin >> n;
    char str[12];
    for(int i=0;i<n;i++)
    {
        cin >> str;
        add(str,i);
    }
    int res=0;
    for(k=0;k<n;k++)
        res+=dfs(k);
//  cout << res << endl;
    for(int i=0;i<v.size();i++)
        if (gTb[i]!=-1)
        {
            ans[gTb[i]]=v[i];
//          cout << i+1 << "    " << gTb[i]+1 << endl;
        }

    bool ok=true;
    for(int i=0;i<n;i++)
        if (ans[i].size()>4||ans[i].size()==0) ok=false;
    if (ok)
        for(int i=0;i<n;i++)
            cout << ans[i] << endl;
    else cout << -1 << endl;
    return 0;
}