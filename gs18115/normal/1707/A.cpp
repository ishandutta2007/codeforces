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
        int n,q;
        cin>>n>>q;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        auto cv=v;
        sort(all(cv));
        cv.erase(unique(all(cv)),cv.end());
        vector<int>miq(n+1,0);
        for(int i=n;i-->0;)
        {
            if(miq[i+1]<v[i])
                miq[i]=miq[i+1]+1;
            else
                miq[i]=miq[i+1];
        }
        int c=0;
        pi ans(0,-inf);
        for(int i=0;i<n;i++)
        {
            if(miq[i]<=q)
                ans=max(ans,pi(c+(n-i),i));
            if(v[i]<=q)
                c++;
        }
        ans=max(ans,pi(c,n));
        for(int i=0;i<n;i++)
            cout<<(v[i]<=q||i>=ans.se?'1':'0');
        cout<<'\n';
    }
    return 0;
}