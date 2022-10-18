#include<iostream>
#include<cstdio>
#include<string>
#include<cassert>
using namespace std;
int n,node[5001];
string s[5001];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i]=" "+s[i];
        assert(s[i].length()==n+1);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(s[i][j]=='1')
                if(!node[i]||s[j][node[i]]=='1')
                    node[i]=j;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(node[i]&&s[node[i]][j]=='1'&&s[j][i]=='1')
            {
                cout<<i<<" "<<node[i]<<" "<<j<<'\n';
                return 0;
            }
    cout<<"-1\n";
    return 0;
}