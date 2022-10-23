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
string ver[2]={"NO\n","YES\n"};
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
        int r1,c1,r2,c2,r3,c3;
        cin>>r1>>c1>>r2>>c2>>r3>>c3;
        int x,y;
        cin>>x>>y;
        int r,c;
        if(r1==r2||r1==r3)
            r=r1;
        else
            r=r2;
        if(c1==c2||c1==c3)
            c=c1;
        else
            c=c2;
        if(pi(x,y)==pi(r1,c1))
            cout<<ver[1];
        else if(pi(x,y)==pi(r2,c2))
            cout<<ver[1];
        else if(pi(x,y)==pi(r3,c3))
            cout<<ver[1];
        else if(r==x||c==y)
            cout<<ver[1];
        else if((r==1||r==n)&&(c==1||c==n))
            cout<<ver[0];
        else if((r+c)%2==(x+y)%2)
            cout<<ver[r%2==x%2];
        else
            cout<<ver[1];
    }
    return 0;
}