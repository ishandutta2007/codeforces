#include<iostream>
#include<vector>
#include<algorithm>
#include <string>

#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        vector<vector<pair<char,int> > >vv;
        for(int i=0;i<2;i++)
        {
            vector<pair<char,int> >v;
            string s;
            cin>>s;
            int n=s.size();
            char prv='B';
            int cc=0,bc=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='A'||s[i]=='C')
                {
                    if(s[i]!=prv)
                    {
                        v.eb(prv,cc);
                        prv=s[i];
                        cc=1;
                    }
                    else
                        cc++;
                }
                else
                    bc++;
            }
            v.eb(prv,cc);
            while(1)
            {
                bool f=0;
                int ii=0;
                int m=v.size();
                for(int i=0;i<m;i++)
                    if(v[i].se%2==0)
                    {
                        ii=i,f=1;
                        break;
            }
                if(!f)
                    break;
                if(ii==0)
                    v.erase(v.begin());
                else if(ii==m-1)
                    v.pop_back();
                else
                {
                    v[ii-1].se+=v[ii+1].se;
                    v.erase(v.begin()+ii+1);
                    v.erase(v.begin()+ii);
                }
            }
            for(auto&t:v)
                t.se%=2;
            v.eb('B',bc%2);
            vv.eb(v);
        }
        if(vv[0]==vv[1])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}