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
        vector<int>a(n);
        vector<int>b(n);
        for(int&t:a)
            cin>>t;
        for(int&t:b)
            cin>>t;
        sort(all(a));
        sort(all(b));
        for(int&t:a)
            cout<<t<<' ';
        cout<<'\n';
        for(int&t:b)
            cout<<t<<' ';
        cout<<'\n';
    }
    cout.flush();
    return 0;
}