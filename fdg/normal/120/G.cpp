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

int a[2][102],b[2][102];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,t;
    cin >> n >> t;
    for(int i=0;i<n;i++)
        cin >> a[0][i] >> b[0][i] >> a[1][i] >> b[1][i];
    int m,c[102]={0};
    cin >> m;
    string word[102];
    for(int i=0;i<m;i++)
        cin >> word[i] >> c[i];
    bool ok[102]={0};
    int d[102][102]={0};
    int left=m,cur=0,player=0,lt=t;
    vector < vector <string> > ans(n);
    while(left)
    {
        while(ok[cur]) cur=(cur+1)%m;
        int team,num;
        if (player<n) team=player,num=0;
        else team=player-n,num=1;
        int time=max(1,c[cur]-(a[num][team]+b[num^1][team])-d[cur][team]);
        if (time<=lt)
        {
            ok[cur]=true;
//          cout << team << "   " << word[cur] << endl;
            ans[team].push_back(word[cur]);
            lt-=time; left--;
            if (lt) continue;
        }
        else d[cur][team]+=lt;
        lt=t; player=(player+1)%(2*n); cur=(cur+1)%m;
    }
    for(int i=0;i<n;i++)
    {
        cout << ans[i].size();
        for(int j=0;j<ans[i].size();j++)
            cout << " " << ans[i][j];
        cout << endl;
    }
    return 0;
}