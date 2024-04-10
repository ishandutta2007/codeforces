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
    vector<vector<int> >ov;
    while(true)
    {
        int mi=0;
        for(int i=1;i<n;i++)
        {
            int poi=find(all(v),i)-v.begin();
            int poj=find(all(v),i+1)-v.begin();
            if(poi>poj)
            {
                mi=i;
                break;
            }
        }
        if(mi==0)
            break;
        int poi=find(all(v),mi)-v.begin();
        int poj=find(all(v),mi+1)-v.begin();
        int nj=poj;
        while(nj<n&&v[nj]==nj-poj+mi+1)
            nj++;
        ov.eb(vector<int>());
        if(poj!=0)
            ov.back().eb(poj);
        ov.back().eb(nj-poj);
        ov.back().eb(poi+1-nj);
        if(poi!=n-1)
            ov.back().eb(n-(poi+1));
        vector<int>nv;
        int prv=n;
        for(int i=(int)ov.back().size();i-->0;)
        {
            int t=ov.back()[i];
            for(int i=prv-t;i<prv;i++)
                nv.eb(v[i]);
            prv-=t;
        }
        v=nv;
    }
    cout<<ov.size()<<'\n';
    for(auto&op:ov)
    {
        cout<<op.size();
        for(int&t:op)
            cout<<' '<<t;
        cout<<'\n';
    }
    return 0;
}