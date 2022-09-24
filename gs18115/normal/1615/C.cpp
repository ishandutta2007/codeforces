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
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        int c00=0,c01=0,c10=0,c11=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0'&&t[i]=='0')
                c00++;
            if(s[i]=='0'&&t[i]=='1')
                c01++;
            if(s[i]=='1'&&t[i]=='0')
                c10++;
            if(s[i]=='1'&&t[i]=='1')
                c11++;
        }
        if(s==t)
            cout<<0<<'\n';
        else if(c10+c11==0)
            cout<<-1<<'\n';
        else
        {
            int m=inf;
            if(c10==c01)
            { //even number of change
                m=min(m,c01*2);
            }
            if(c11==c00+1) //c11-c00==1 / c11=c00+1
            { //odd number of change
                m=min(m,c11+c00);
            }
            if(m==inf)
                m=-1;
            cout<<m<<'\n';
        }
    }
    return 0;
}