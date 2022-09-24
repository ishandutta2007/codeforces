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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int wc=0,clc=0;
        bool win=0,pw=0;
        vector<int>v2;
        int ans=0;
        for(auto t:s)
        {
            if(t=='W')
            {
                if(clc>0&&win)
                {
                    v2.eb(clc);
                    clc=0;
                }
                if(clc>0)
                    clc=0;
                ans++;
                win=1;
                if(pw)
                    ans++;
                pw=1;
                wc++;
            }
            else
                pw=0,clc++;
        }
        if(wc==0)
        {
            cout<<max(0,2*k-1)<<'\n';
            continue;
        }
        sort(all(v2));
        for(int&t:v2)
        {
            if(t>k)
                break;
            k-=t;
            ans+=t*2+1;
        }
        ans+=2*k;
        ans=min(ans,n*2-1);
        cout<<ans<<'\n';
    }
    return 0;
}