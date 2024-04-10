#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int di[4]={1,0,-1,0},dj[4]={0,1,0,-1};
char S[70];
int N[70];
int r,c,cc,i;
char s[105][105],x[105][105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=0;i<10;i++)
        S[i]='0'+i;
    for(i=10;i<36;i++)
        S[i]='A'+(i-10);
    for(i=36;i<62;i++)
        S[i]='a'+(i-36);
    int t;
    cin>>t;
    while(t-->0)
    {
        int k;
        cin>>r>>c>>k;
        for(i=0;i++<r;)
            cin>>s[i]+1;
        int j;
        cc=0;
        int c2=0;
        for(i=0;i++<r;)
            for(j=0;j++<c;)
                if(s[i][j]=='R')
                    c2++;
        int d=c2/k;
        int C=0;
        for(i=0;i<k;i++)
        {
            if((k-i)*(d+1)+C>c2)
                N[i]=d;
            else
                N[i]=d+1;
            C+=N[i];
        }
        int c3=0,c4=0;
        for(i=0;i++<r;)
        {
            if(i&1)
            {
                for(j=0;j++<c;)
                {
                    if(s[i][j]=='R')
                    {
                        if(N[c3]==c4)
                            c4=0,c3++;
                        c4++;
                    }
                    x[i][j]=S[c3];
                }
            }
            else
            {
                for(j=c;j>0;j--)
                {
                    if(s[i][j]=='R')
                    {
                        if(N[c3]==c4)
                            c4=0,c3++;
                        c4++;
                    }
                    x[i][j]=S[c3];
                }
            }
        }
        for(i=0;i++<r;)
            x[i][c+1]=0,cout<<x[i]+1<<'\n';
    }
    cout<<endl;
    return 0;
}