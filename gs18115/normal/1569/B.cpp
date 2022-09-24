#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
char mp[205][205];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>>tc;
    for(int tci=0;tci<tc;tci++)
    {
        int n;
        string s;
        cin>>n>>s;
        vector<int>v;
        for(int i=0;i<n;i++)
            if(s[i]=='2')
                v.eb(i);
        if(v.empty()||(int)v.size()>2)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    mp[i][j]='=';
            for(int i=0;i<n;i++)
                mp[i][i]='X';
            for(int i=0;i<(int)v.size();i++)
                mp[v[i]][i==0?v.back():v[i-1]]='+',mp[i==0?v.back():v[i-1]][v[i]]='-';
            cout<<"YES\n";
            for(int i=0;i<n;cout<<'\n',i++)
                for(int j=0;j<n;j++)
                    cout<<mp[i][j];
        }
        else
            cout<<"NO\n";
    }
    return 0;
}