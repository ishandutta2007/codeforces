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
string a,b;
int cnt1[300],cnt2[300];
bool used[200111];
int main()
{
    cin>>a>>b;
    for(int i=0;i<a.size();i++)cnt1[a[i]]++;
    for(int j=0;j<b.size();j++)cnt2[b[j]]++;
    int r1=0,r2=0;
    for(int i=0;i<a.size();i++)
    {
        if(cnt2[a[i]]>0)
        {
            r1++;cnt2[a[i]]--;used[i]=1;
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if(used[i])continue;
        if('a'<=a[i]&&a[i]<='z'&&cnt2[a[i]+'A'-'a']>0)cnt2[a[i]+'A'-'a']--,r2++;
        else if('A'<=a[i]&&a[i]<='Z'&&cnt2[a[i]+'a'-'A']>0)cnt2[a[i]+'a'-'A']--,r2++;
    }
    cout<<r1<<" "<<r2<<endl;
    return 0;
}