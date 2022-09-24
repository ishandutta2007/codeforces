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
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        v.eb(v[0]);
        bool f=1;
        for(int i=0;i<n;i++)
            if(v[i]!=v[i+1])
                f=0;
        if(f)
        {
            cout<<1<<'\n';
            for(int i=0;i<n;i++)
                cout<<1<<' ';
            cout<<'\n';
        }
        else if(n%2==0)
        {
            cout<<2<<'\n';
            for(int i=0;i<n;i++)
                cout<<(i&1)+1<<' ';
            cout<<'\n';
        }
        else
        {
            int pos=-1;
            for(int i=0;i<n;i++)
            {
                if(v[i]==v[i+1])
                {
                    pos=i;
                    break;
                }
            }
            if(pos==-1)
            {
                cout<<3<<'\n';
                for(int i=1;i<n;i++)
                    cout<<(i&1)+1<<' ';
                cout<<3;
            }
            else
            {
                cout<<2<<'\n';
                for(int i=0;i<n;i++)
                {
                    if(i<=pos)
                        cout<<(i&1)+1<<' ';
                    else
                        cout<<(i+1&1)+1<<' ';
                }
            }
            cout<<'\n';
        }
    }
    cout.flush();;
    return 0;
}