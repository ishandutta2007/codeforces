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
string s;
int n;
bool a[500111];
double ans,sum[500111],sum2[500111];
bool vowel(char c)
{
    if(c=='A'||c=='E'||c=='O'||c=='I'||c=='U'||c=='Y')return true;else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>s;n=s.size();
    for(int i=n;i>=1;i--)sum[i]=sum[i+1]+1.0/i;
    for(int i=n;i>=1;i--)sum2[i]=sum2[i+1]+sum[i];
    for(int i=0;i<s.size();i++)a[i+1]=vowel(s[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i])
        {
            ans-=sum2[i+1]+sum2[n-i+2]-n;
        }
    }
    cout<<fixed<<ans<<endl;
    return 0;
}