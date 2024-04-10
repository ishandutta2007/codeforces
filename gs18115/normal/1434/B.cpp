#include<iostream>
#include<vector>
#include<set>
#include<map>
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
    int c=0;
    vector<int>pr(n);
    vector<int>stk;
    vector<pi>qv;
    for(int i=0;i<n*2;i++)
    {
        char ch;
        cin>>ch;
        if(ch=='+')
        {
            qv.eb(0,c);
            stk.eb(c);
            c++;
        }
        else
        {
            int p;
            cin>>p;
            qv.eb(1,p);
            if(stk.empty())
                return cout<<"NO"<<endl,0;
            int id=stk.back();
            stk.pop_back();
            pr[id]=p;
        }
    }
    set<int>st;
    for(pi&qt:qv)
    {
        if(qt.fi==0)
            st.ep(pr[qt.se]);
        else
        {
            if(*st.begin()!=qt.se)
                return cout<<"NO"<<endl,0;
            st.erase(st.begin());
        }
    }
    cout<<"YES"<<endl;
    for(int&t:pr)
        cout<<t<<' ';
    cout<<endl;
    return 0;
}