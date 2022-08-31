#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    map<pair<int, int>, pair<int,int>> mp; // mp[a x b] -> {max c, index of the max c cuboid}
    // 0 100 x 200 x 5 -> 100 x 200 x 8
    // 1 200 x 6 x 100 -> 100 x 200 x 9
    // 2 100 x 200 x 3

    pair<int, int> ans = {-1, -1}; //indices
    int max_diameter = 0; 

    for(int i=0; i<n; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        if(min({a, b, c}) > max_diameter)
        {
            max_diameter = min({a, b, c});
            ans = {i, -1};
        }
        if(min({a, b, c + mp[{a, b}].first}) > max_diameter)
        {
            max_diameter = min({a, b, c + mp[{a, b}].first});
            ans = {i, mp[{a, b}].second};
        }
        if(min({a, b + mp[{a, c}].first, c}) > max_diameter)
        {
            max_diameter = min({a, b + mp[{a, c}].first, c});
            ans = {i, mp[{a, c}].second};
        }
        if(min({a + mp[{b, c}].first, b, c}) > max_diameter)
        {
            max_diameter = min({a + mp[{b, c}].first, b, c});
            ans = {i, mp[{b, c}].second};
        }

        mp[{a, b}] = max(mp[{a, b}], {c, i});
        mp[{b, a}] = max(mp[{b, a}], {c, i});
        mp[{a, c}] = max(mp[{a, c}], {b, i});
        mp[{c, a}] = max(mp[{c, a}], {b, i});
        mp[{b, c}] = max(mp[{b, c}], {a, i});
        mp[{c, b}] = max(mp[{c, b}], {a, i});
    }

    if(ans.second == -1) cout<<1<<'\n'<<ans.first+1;
    else cout<<2<<'\n'<<ans.first+1<<' '<<ans.second+1;


    return 0;
}