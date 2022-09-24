#include<iostream>
#include<vector>
#include<set>
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
        set<int>s;
        vector<int>v(n);
        for(int&t:v)
        {
            cin>>t;
            if(s.count(t))
                s.insert(-t);
            else
                s.insert(t);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}