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
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        vector<int>dl(n);
        for(int&t:v)
            cin>>t;
        for(int&t:dl)
        {
            char c;
            cin>>c;
            t=c=='0'?0:1;
        }
        vector<int>lv,dv;
        for(int i=0;i<n;i++)
            (dl[i]==0?dv:lv).eb(v[i]);
        sort(all(lv)),sort(all(dv));
        int bi=dv.size();
        for(int i=0;i<n;i++)
        {
            int j;
            if(dl[i]==0)
                j=upper_bound(all(dv),v[i])-dv.begin();
            else
                j=upper_bound(all(lv),v[i])-lv.begin()+bi;
            cout<<j<<' ';
        }
        cout<<endl;
    }
    return 0;
}