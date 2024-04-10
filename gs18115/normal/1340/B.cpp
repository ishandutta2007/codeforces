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
const ll INF=1e18+7;
const string bit[10]={
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};
int ibit[10];
bool dp[2010][2010];
int dig[2010][2010];
vector<int>lst[2][10];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<10;i++)
        for(int j=0;j<7;j++)
            if(bit[i][j]=='1')
                ibit[i]|=1<<j;
    int n,k;
    cin>>n>>k;
    vector<int>in(n,0);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<7;j++)
            if(s[j]=='1')
                in[i]|=1<<j;
    }
    dp[n][0]=1;
    lst[0][0].eb(0);
    for(int i=n;i>0;i--)
    {
        int par=(n-i)&1;
        for(int j=0;j<10;j++)
        {
            for(int&t:lst[par][j])
            {
                if(dig[i][t]!=j)
                    continue;
                for(int l=10;l-->0;)
                {
                    if((in[i-1]&ibit[l])!=in[i-1])
                        continue;
                    int ch=__builtin_popcount(in[i-1]^ibit[l]);
                    if(t+ch>k)
                        continue;
                    if(!dp[i-1][t+ch])
                    {
                        dp[i-1][t+ch]=1;
                        dig[i-1][t+ch]=l;
                        lst[par^1][l].eb(t+ch);
                    }
                    else if(dig[i-1][t+ch]<l)
                    {
                        dig[i-1][t+ch]=l;
                        lst[par^1][l].eb(t+ch);
                    }
                }
            }
            lst[par][j].clear();
        }
    }
    if(!dp[0][k])
        return cout<<-1<<endl,0;
    int c=k;
    for(int i=0;i<n;i++)
    {
        cout<<dig[i][c];
        int ch=__builtin_popcount(in[i]^ibit[dig[i][c]]);
        c-=ch;
    }
    cout<<endl;
    return 0;
}