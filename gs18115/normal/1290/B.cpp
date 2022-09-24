#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
int sum[200010][26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<26;j++)
            sum[i+1][j]=sum[i][j];
        sum[i+1][s[i]-'a']++;
    }
    int q;
    cin>>q;
    while(q-->0)
    {
        int l,r;
        cin>>l>>r;
        if(s[l-1]!=s[r-1]||l==r)
            cout<<"YES";
        else
        {
            int c=0;
            for(int i=0;i<26;i++)
                if(sum[r][i]-sum[l-1][i]>0)
                    c++;
            cout<<(c>2?"YES":"NO");
        }
        cout<<'\n';
    }
    return 0;
}