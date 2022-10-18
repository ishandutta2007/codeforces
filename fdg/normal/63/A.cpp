#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stack>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    vector < pair <string,int> > f;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s1,s2;
        int t=0;
        cin >> s1 >> s2;
        if (s2=="captain") t=5;
        if (s2=="man") t=4;
        if (s2=="child"||s2=="woman") t=3;
        if (s2=="rat") t=2;
        f.push_back(make_pair(s1,t));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if (f[j].second>f[j+1].second) swap(f[j],f[j+1]);
        }
    }
    for(int i=0;i<n;i++)
        cout << f[i].first << endl;
    return 0;
}