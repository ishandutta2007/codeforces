#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    list<int> l1;
    int k1;
    cin>>k1;
    for(int i = 0; i<k1; i++)
    {
        int t;
        cin>>t;
        l1.push_back(t);
    }

    list<int> l2;
    int k2;
    cin>>k2;
    for(int i = 0; i<k2; i++)
    {
        int t;
        cin>>t;
        l2.push_back(t);
    }

    set<pair<list<int>, list<int> > > st;

    while(!l1.empty() && !l2.empty() && !st.count(make_pair(l1, l2)))
    {
        st.insert(make_pair(l1, l2));

        if(l1.front() > l2.front())
        {
            l1.push_back(l2.front());
            l2.pop_front();

            l1.push_back(l1.front());
            l1.pop_front();
        }
        else
        {
            l2.push_back(l1.front());
            l1.pop_front();

            l2.push_back(l2.front());
            l2.pop_front();
        }
    }

    if(l1.empty()) cout<<st.size()<<' '<<2;
    else if(l2.empty()) cout<<st.size()<<' '<<1;
    else cout<<-1;

    return 0;
}