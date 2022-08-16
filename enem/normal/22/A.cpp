#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    set<int> st;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        st.insert(t);
    }

    auto it = st.begin();
    it++;
    if(it!=st.end()) cout<<(*it);
    else cout<<"NO";

    return 0;
}