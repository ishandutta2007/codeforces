//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m;
char s[55][55];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i+=2)
    {
        for(int j=1;j<=m;j++)s[i][j]='#';
    }
    for(int i=2;i<=n;i+=4)s[i][m]='#';
    for(int i=4;i<=n;i+=4)s[i][1]='#';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]!='#')cout<<'.';else cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}