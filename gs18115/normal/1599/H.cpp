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
inline int qry(int x,int y)
{
    cout<<"? "<<x<<' '<<y<<endl;
    cin>>x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    const int n=1e9;
    int c1=qry(1,1);
    int c2=qry(1,n);
    int c3=qry(n,1);
    int s=1,e=min(n,c1+1);
    while(s<e)
    {
        int m=s+(e-s+1)/2;
        int d=qry(1,m);
        if(c1-d==m-1)
            s=m;
        else
            e=m-1;
    }
    // corner 1 is c1-s,s
    int x=c1-s+2,y=s;
    int p=n-(c3-(y-1)),q=n-(c2-(x-1));
    cout<<"! "<<x<<' '<<y<<' '<<p<<' '<<q<<endl;
    return 0;
}