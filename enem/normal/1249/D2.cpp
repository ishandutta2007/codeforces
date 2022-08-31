#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin>>n>>k;

    pair<pair<int, int>,int> a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i].first.first>>a[i].first.second;

        a[i].second = i; // original index
    }

    sort(a, a+n); // so all segments are ordered according to their starting points

    set<pair<int,int>> st; // This stores all of the ending points of currently covering segments + indices of those segments

    vector<int> ans; // This stores all the indices of the segments that I have removed

    for(int i=0; i<n; i++)
    {
        while(!st.empty() && (*st.begin()).first < a[i].first.first)
        {
            st.erase(st.begin());
        }

        st.insert({a[i].first.second, a[i].second});

        while((int)st.size()>k)
        {
            auto it = st.end();
            it--;
            ans.push_back((*it).second);
            st.erase(it);
        }
    }

    cout<<ans.size()<<'\n';
    for(auto it:ans) cout<<it+1<<' ';

    return 0;
}