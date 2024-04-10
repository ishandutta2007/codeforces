#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin>>n>>k;

    pair<int, int> a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i].second>>a[i].first;
    }

    sort(a, a+n);

    multiset<int> st;
    long long sm = 0;
    long long ans = 0;

    for(int i=n-1; i>=0; i--)
    {
        sm += a[i].second;
        st.insert(a[i].second);

        while((int)st.size()>k)
        {
            sm -= (*st.begin());
            st.erase(st.begin());
        }

        ans = max(ans, a[i].first*sm);
    }

    cout<<ans;

    return 0;
}