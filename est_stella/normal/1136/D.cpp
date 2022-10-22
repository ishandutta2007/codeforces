#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;

int main()
{
    int n, m, ans=0, cnt=0;
    scanf("%d%d", &n, &m);

    vector<int> s(n+1);
    vector<bool> chk(n+1);
    vector<int> d(n+1, 0);
    vector< vector<int> > v(n+1);

    for(int i=1; i<=n; i++) {
        int a;
        scanf("%d", &a);
        s[a]=i;
    }

    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        a=s[a];
        b=s[b];
        if(a>=b) continue;

        if(b==n)
        {
            chk[a]=true;
        }
        else
        {
            d[a]++;
            v[b].push_back(a);
        }
    }

    for(int i=n-1; i>0; i--)
    {
        if(chk[i] && d[i]==cnt)
        {
            ans++;
            for(int j=0; j<v[i].size(); j++)
            {
                d[v[i][j]]--;
            }
        }
        else cnt++;
    }

    printf("%d", ans);
}