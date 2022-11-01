#include <bits/stdc++.h>

using namespace std;

bool used[302][302];

void nxt(int a, int b, int& oa, int& ob)
{
    if(!used[a][b+1])
        oa=a, ob=b+1;
    else if(!used[a+1][b])
        oa=a+1, ob=b;
    else if(!used[a][b-1])
        oa=a, ob=b-1;
    else if(!used[a-1][b])
        oa=a-1, ob=b;
    else
    {
        oa=-1, ob=-1;
        return;
    }
    used[oa][ob]=true;
}

int main()
{
    int n, m, k;
    memset(used, true, sizeof used);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            used[i][j]=false;
    int x=1, y=1;
    used[x][y]=true;
    vector<vector<pair<int, int> > > output;
    vector<pair<int, int> > temp;
    for(int i=1; i<k; i++)
    {
        temp.clear();
        temp.push_back(make_pair(x, y));
        nxt(x, y, x, y);
        temp.push_back(make_pair(x, y));
        nxt(x, y, x, y);
        output.push_back(temp);
    }
    temp.clear();
    do
    {
        temp.push_back(make_pair(x, y));
        nxt(x, y, x, y);
    }
    while(x!=-1);
    output.push_back(temp);
    for(size_t i=0; i<output.size(); i++)
    {
        cout<<output[i].size();
        for(size_t j=0; j<output[i].size(); j++)
            cout<<" "<<output[i][j].first<<" "<<output[i][j].second;
        cout<<'\n';
    }
    return 0;
}