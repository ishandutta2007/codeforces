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
const int mxn=100000;
struct seg
{
    int st[mxn*4+10];
    seg()
    {
        fill(st,st+mxn*4+10,0);
    }
    void upd(int n,int s,int e,int x,int p)
    {
        if(s==e)
        {
            st[n]+=p;
            return;
        }
        int m=s+(e-s)/2;
        if(x>m)
            upd(n*2+1,m+1,e,x,p);
        else
            upd(n*2,s,m,x,p);
        st[n]=st[n*2]+st[n*2+1];
        return;
    }
    int qry(int n,int s,int e,int x)
    {
        if(st[n]==0||x>e)
            return -1;
        if(s==e)
            return s;
        int m=s+(e-s)/2;
        int q=qry(n*2,s,m,x);
        if(q==-1)
            return qry(n*2+1,m+1,e,x);
        return q;
    }
}st;
void dnc(int s,int e,vector<vector<int> >&vv,vector<int>&av,int f)
{
    if(s==e)
    {
        if(f==1)
            for(int&t:vv[s])
                cout<<0;
        else
        {
            auto&v=vv[s];
            ll sm=0;
            int k=v.size();
            for(int&t:v)
                sm+=t;
            k--;
            for(int&t:v)
            {
                int q=st.qry(1,1,mxn,(sm-t+k-1)/k);
                if(q==-1)
                    cout<<0;
                else
                    cout<<1;
            }
        }
        return;
    }
    int m=s+(e-s)/2;
    if(f==1)
    {
        dnc(s,m,vv,av,f);
        dnc(m+1,e,vv,av,f);
    }
    else
    {
        vector<int>tmp;
        int af=0,bf=0;
        for(int i=m+1;i<=e;i++)
        {
            int q=st.qry(1,1,mxn,av[i]);
            if(q==-1)
                bf=1;
            else
                tmp.eb(q),st.upd(1,1,mxn,q,-1);
        }
        dnc(s,m,vv,av,bf);
        for(int&t:tmp)
            st.upd(1,1,mxn,t,1);
        tmp.clear();
        for(int i=s;i<=m;i++)
        {
            int q=st.qry(1,1,mxn,av[i]);
            if(q==-1)
                af=1;
            else
                tmp.eb(q),st.upd(1,1,mxn,q,-1);
        }
        dnc(m+1,e,vv,av,af);
        for(int&t:tmp)
            st.upd(1,1,mxn,t,1);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tct;
    cin>>tct;
    while(tct-->0)
    {
        int n,m;
        cin>>n>>m;
        vector<int>v(n);
        for(int&t:v)
            cin>>t;
        vector<vector<int> >std(m);
        vector<int>aver;
        for(auto&cv:std)
        {
            ll sm=0;
            int k;
            cin>>k;
            cv.resize(k);
            for(int&t:cv)
                cin>>t,sm+=t;
            aver.eb((sm+k-1)/k);
        }
        for(int&t:v)
            st.upd(1,1,mxn,t,1);
        dnc(0,m-1,std,aver,0);
        for(int&t:v)
            st.upd(1,1,mxn,t,-1);
        cout<<'\n';
    }
    return 0;
}