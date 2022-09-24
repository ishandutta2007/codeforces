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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c=0,c2=0,ss=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            c++;
        else
            c--;
        if(c>=0&&c2!=0)
            ss+=c2+1,c2=0;
        else if(c<0)
            c2++;
    }
    if(c!=0)
        return cout<<-1<<endl,0;
    cout<<ss<<endl;
    return 0;
}