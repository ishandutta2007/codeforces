#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int> > v;

bool chk(int k)
{
    for(int i=0; i<v.size(); i++)
    {
        int x = (v[i].first+k)%n;
        int y = (v[i].second+k)%n;
        if(x > y) swap(x, y);
        if(!binary_search(v.begin(), v.end(), make_pair(x, y))) return false;
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);

    for(int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        if(a > b) swap(a, b);

        v.push_back({a-1, b-1});
    }

    sort(v.begin(), v.end());

    for(int i=1; i<n; i++)
    {
        if(n%i) continue;

        if(chk(i))
        {
            printf("Yes");
            return 0;
        }
    }

    printf("No");
}