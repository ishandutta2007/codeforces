#include<iostream>
#include<vector>
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
const int mod=998244353;
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y)
{
    return x<y?x+mod-y:x-y;
}
inline int mul(int x,int y)
{
    return(int)((ll)x*y%mod);
}
inline int pw(int x,int y)
{
    int ret=1;
    while(y>0)
    {
        if(y%2==1)
            ret=mul(ret,x);
        x=mul(x,x);
        y/=2;
    }
    return ret;
}
int tor[50],pri[50];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,a,h;
    cin>>k>>a>>h;
    if(k<5)
    {
        int k2=(1<<k)-1;
        bool f=0;
        for(int X=0;X<1<<k2;X++)
        {
            for(int i=0;i<1<<k;i++)
                tor[i]=i+1;
            int cs=0;
            for(int j=k;j-->0;)
            {
                int num=1<<j;
                for(int x=0;x<num;x++)
                {
                    if(X>>(cs+x)&1)
                        swap(tor[x*2],tor[x*2+1]);
                    pri[tor[x*2+1]]=num+1;
                    tor[x]=tor[x*2];
                }
                cs+=num;
            }
            pri[tor[0]]=1;
            int hs=0;
            for(int i=0;i++<1<<k;)
                hs=add(hs,mul(i,pw(a,pri[i])));
            if(hs==h)
            {
                for(int i=0;i++<1<<k;)
                    cout<<pri[i]<<' ';
                f=1;
                break;
            }
        }
        if(!f)
            cout<<-1;
        cout<<'\n';
    }
    else
    {
        map<int,int>mp;
        vector<int>cv;
        for(int i=0;i<1;i++)
            cv.eb(1);
        for(int i=0;i<1;i++)
            cv.eb(2);
        for(int i=0;i<2;i++)
            cv.eb(3);
        for(int i=0;i<4;i++)
            cv.eb(5);
        for(int i=0;i<8;i++)
            cv.eb(9);
        {
            for(int i=0;i<1<<16;i++)
            {
                int s=0;
                for(int j=0;j<16;j++)
                {
                    if(i>>j&1)
                    {
                        int prv=cv[j];
                        int nxt=17;
                        s=add(s,sub(pw(a,prv),pw(a,nxt)));
                    }
                }
                mp[s]=i;
            }
        }
        int k2=15;
        bool f=0;
        for(int X=0;X<1<<k2;X++)
        {
            for(int i=0;i<16;i++)
                tor[i]=i*2+1,pri[i*2+2]=17;
            int cs=0;
            for(int j=k-1;j-->0;)
            {
                int num=1<<j;
                for(int x=0;x<num;x++)
                {
                    if(X>>(cs+x)&1)
                        swap(tor[x*2],tor[x*2+1]);
                    pri[tor[x*2+1]]=num+1;
                    tor[x]=tor[x*2];
                }
                cs+=num;
            }
            pri[tor[0]]=1;
            int hs=0;
            for(int i=0;i++<1<<k;)
                hs=add(hs,mul(i,pw(a,pri[i])));
            auto it=mp.find(sub(h,hs));
            if(it!=mp.end())
            {
                int D=it->se;
                vector<int>v1;
                for(int j=0;j<16;j++)
                    if(D>>j&1)
                        v1.eb(cv[j]);
                vector<pi>v2;
                for(int j=0;j<32;j++)
                    if(pri[j]<17)
                        v2.eb(pri[j],j);
                sort(all(v2));
                for(int i=0,j=0;i<(int)v2.size()&&j<(int)v1.size();i++)
                {
                    if(v2[i].fi==v1[j])
                    {
                        swap(pri[v2[i].se],pri[v2[i].se+1]);
                        j++;
                    }
                }
                for(int i=0;i++<1<<k;)
                    cout<<pri[i]<<' ';
                f=1;
                break;
            }
        }
        if(!f)
            cout<<-1;
        cout<<'\n';
    }
    return 0;
}