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
const int MAX=500000;
vector<pi>ct;
pi ans;
int prmn[500010],prmx[500010],sfmn[500010],sfmx[500010];
inline bool able(int x)
{
    for(int i=0;i<=MAX;i++)
        prmx[i]=sfmx[i]=-MAX,prmn[i]=sfmn[i]=MAX*2;
    int tmn=0;
    int tmx=MAX;
    for(pi&t:ct)
    {
        tmn=max(tmn,t.fi-x);
        tmx=min(tmx,t.fi+x);
        prmx[t.fi]=max(prmx[t.fi],t.se-x-t.fi);
        prmn[t.fi]=min(prmn[t.fi],t.se+x);
        sfmx[t.fi]=max(sfmx[t.fi],t.se-x);
        sfmn[t.fi]=min(sfmn[t.fi],t.se+x-t.fi);
    }
    for(int i=0;i++<MAX;)
        prmx[i]=max(prmx[i],prmx[i-1]),prmn[i]=min(prmn[i],prmn[i-1]);
    for(int i=MAX;i-->0;)
        sfmx[i]=max(sfmx[i],sfmx[i+1]),sfmn[i]=min(sfmn[i],sfmn[i+1]);
    for(int i=tmn;i<=tmx;i++)
    {
        int lb=max({0,sfmx[i],prmx[i]+i});
        int ub=min({MAX,prmn[i],sfmn[i]+i});
        if(lb<=ub)
        {
            ans=pi(i,lb);
            return 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    ct.resize(n,pi(0,0));
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(auto&t:s)
            (t=='B'?ct[i].fi:ct[i].se)++;
    }
    int s=0,e=MAX;
    while(s<e)
    {
        int m=s+(e-s)/2;
        if(able(m))
            e=m;
        else
            s=m+1;
    }
    able(s);
    if(ans==pi(0,0))
        ans=pi(1,1);
    cout<<s<<endl;
    for(int i=0;i<ans.fi;i++)
        cout<<'B';
    for(int i=0;i<ans.se;i++)
        cout<<'N';
    cout<<endl;
    return 0;
}