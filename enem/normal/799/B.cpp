#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int p[n], a[n], b[n];
    for(int i=0; i<n; i++) cin>>p[i];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    vector<int> v[4][4];

    for(int i=0; i<n; i++)
    {
        v[a[i]][b[i]].push_back(p[i]);
    }

    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            sort(v[i][j].begin(), v[i][j].end(), [](int x, int y)->bool{return x>y;});
        }
    }

    int m;
    cin>>m;
    while(m--)
    {
        int t;
        cin>>t;

        pair<int, int> mn = {-1, -1};

        for(int i=1; i<=3; i++)
        {
            if(!v[t][i].empty() && (mn == make_pair(-1, -1) || v[t][i].back() < v[mn.first][mn.second].back()))
            {
                mn = {t, i};
            }
            if(!v[i][t].empty() && (mn == make_pair(-1, -1) || v[i][t].back() < v[mn.first][mn.second].back()))
            {
                mn = {i, t};
            }
        }

        if(mn == make_pair(-1, -1)) cout<<-1<<' ';
        else
        {
            cout<<v[mn.first][mn.second].back()<<' ';
            v[mn.first][mn.second].pop_back();
        }
    }


    return 0;
}