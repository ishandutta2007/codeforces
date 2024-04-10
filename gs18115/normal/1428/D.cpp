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
    int n;
    cin>>n;
    vector<int>v(n);
    for(int&t:v)
        cin>>t;
    int ch=0;
    vector<pi>stk,stk2;
    vector<pi>ptv;
    for(int i=n;i-->0;)
    {
        if(v[i]==0)
            continue;
        if(v[i]==1)
        {
            ch++;
            stk.eb(i+1,ch);
            ptv.eb(i+1,ch);
        }
        else if(v[i]==2)
        {
            if(stk.empty())
                return cout<<-1<<endl,0;
            pi cur=stk.back();
            stk.pop_back();
            ptv.eb(i+1,cur.se);
            stk2.eb(i+1,cur.se);
        }
        else
        {
            pi cur;
            if(!stk2.empty())
                cur=stk2.back(),stk2.pop_back();
            else if(!stk.empty())
                cur=stk.back(),stk.pop_back();
            else
                return cout<<-1<<endl,0;
            ch++;
            ptv.eb(i+1,ch);
            ptv.eb(cur.fi,ch);
            stk2.eb(i+1,ch);
        }
    }
    cout<<ptv.size()<<endl;
    for(pi&t:ptv)
        cout<<(n+1-t.se)<<' '<<t.fi<<'\n';
    return 0;
}