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
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        int zc=0;
        vector<int>v2;
        for(int&t:v)
        {
            if(t==0)
                zc++;
            else
                v2.eb(t);
        }
        v=v2;
        n=v.size();
        while(n>1)
        {
            v2.clear();
            if(zc!=0)
                v2.eb(v[0]),zc--;
            for(int i=1;i<n;i++)
                v2.eb(v[i]-v[i-1]);
            sort(all(v2));
            v.clear();
            for(int&t:v2)
            {
                if(t==0)
                    zc++;
                else
                    v.eb(t);
            }
            n=v.size();
        }
        cout<<(n==0?0:v[0]);
        cout<<'\n';
    }
    return 0;
}