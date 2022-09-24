#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    int n=s.size();
    int i;
    int m=30;
    for(i=0;i<n;i++)
    {
        int d=(char)s[i]-'a';
        if(d<=m)
            cout<<"Mike\n";
        else
            cout<<"Ann\n";
        m=min(m,d);
    }
    cout<<endl;
    return 0;
}