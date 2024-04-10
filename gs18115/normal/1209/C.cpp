#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
char s[200010],d[200010];
int n,i,j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tttt;
    cin>>tttt;
    while(tttt-->0)
    {
        cin>>n;
        cin>>s;
        int v=-1;
        int q1,q2,t;
        for(i=0;i<10;i++)
        {
            q1=q2=t=0;
            int r1,r2;
            r2=n;
            for(j=0;j<n;j++)
            {
                d[j]=0;
                int m=s[j]-'0';
                if(m<i)
                {
                    if(m<q1)
                        break;
                    else
                        r1=j,q1=m,d[j]='1';
                }
                else if(m==i)
                    continue;
                else if(m<q2)
                    break;
                else
                    r2=min(r2,j),q2=m,d[j]='2';
            }
            if(j<n)
                continue;
            for(j=0;j<n;j++)
            {
                if(d[j]>0)
                    continue;
                if(j<r2)
                    d[j]='2';
                else if(j>r1)
                    d[j]='1';
                else
                    break;
            }
            if(j>=n)
                break;
        }
        d[n]=0;
        if(i>9)
            cout<<"-\n";
        else
            cout<<d<<'\n';
    }
    return 0;
}