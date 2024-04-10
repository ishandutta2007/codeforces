#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6+10;
int n;
main()
{
    //freopen("baibb.inp","r",stdin);
    int T;cin>>T;
    while(T--)
    {
        cin>>n;
        priority_queue<int> h;
        while(n--)
        {
            int x;cin>>x;
            h.push(x);
        }
        while(h.size()>1)
        {
            int u=h.top();h.pop();
            int v=h.top();h.pop();
            --u,--v;
            if(u) h.push(u);
            if(v) h.push(v);
        }
        if(h.size()) cout<<"T\n";
        else cout<<"HL\n";
    }
}