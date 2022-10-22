#include<bits/stdc++.h>
using namespace std;

int n, k, ans;
int x[100001];
vector<int> lo[100001];

int main()
{
    scanf("%d%d", &n, &k);

    for(int i=1; i<=k; i++)
    {
        scanf("%d", &x[i]);
        lo[x[i]].push_back(i);
    }

    for(int i=1; i<n; i++)
    {
        if(lo[i].empty() || lo[i+1].empty()) ans++;
        else if(lo[i+1][lo[i+1].size()-1] < lo[i][0]) ans++;
    }

    for(int i=2; i<=n; i++)
    {
        if(lo[i].empty() || lo[i-1].empty()) ans++;
        else if(lo[i-1][lo[i-1].size()-1] < lo[i][0]) ans++;
    }

    for(int i=1; i<=n; i++)
        if(lo[i].empty()) ans++;

    printf("%d", ans);
}