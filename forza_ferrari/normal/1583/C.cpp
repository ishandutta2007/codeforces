#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int n,m,q;
string s[1000001];
set<int> st;
int main()
{
    cin>>n>>m;
    for(register int i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i]=" "+s[i];
    }
    for(register int i=2;i<=n;++i)
        for(register int j=2;j<=m;++j)
            if(s[i][j-1]=='X'&&s[i-1][j]=='X')
                st.insert(j);
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(st.lower_bound(x+1)==st.end())
        {
            cout<<"YES"<<endl;
            continue;
        }
        int pos=*st.lower_bound(x+1);
        if(pos<=y)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}