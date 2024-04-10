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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;
        bool f1=1,f2=1;
        vector<bool>chk(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='-')
                chk[i]=chk[(i+1)%n]=1;
            else if(s[i]=='<')
                f1=0;
            else
                f2=0;
        }
        if(f1||f2)
            cout<<n<<'\n';
        else
        {
            int c=0;
            for(int i=0;i<n;i++)
                if(chk[i])
                    c++;
            cout<<c<<'\n';
        }
    }
    return 0;
}