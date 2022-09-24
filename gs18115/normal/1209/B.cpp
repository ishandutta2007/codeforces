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
int n,m,i,j;
int a[105],b[105];
char s[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>s;
    for(i=0;i<n;i++)
        s[i]-='0';
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    for(i=0;i<5*4*3*2*10;i++)
    {
        for(j=0;j<n;j++)
            if(i>=b[j]&&(i-b[j])%a[j]==0)
                s[j]=!s[j];
        int c=0;
        for(j=0;j<n;j++)
            c+=s[j];
        m=max(m,c);
    }
    cout<<m<<endl;
    return 0;
}