#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b;
    cin >> n >> m;
    vector < pair <int,int> > v;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(b,a));
    }
    sort(v.rbegin(),v.rend());
    int ret=0;
    for(int i=0;i<m;i++)
    {
        ret+=min(v[i].second,n)*v[i].first;
        n-=min(v[i].second,n);
    }
    cout << ret << endl;
    return 0;
}