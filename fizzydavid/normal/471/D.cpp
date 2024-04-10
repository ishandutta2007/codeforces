//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,w,a[200011],b[200011],pos[200011];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>w;
    if(w==1)
    {
        cout<<n;
        return 0;
    }
    else if(n<w)
    {
        cout<<"0";
        return 0;
    }
    int x1,x2;cin>>x1;
    for(int i=1;i<n;i++)
    {
        cin>>x2;
        a[i]=x2-x1;
        x1=x2;
    }
    cin>>x1;
    for(int i=1;i<w;i++)
    {
        cin>>x2;
        b[i]=x2-x1;
        x1=x2;
    }
    n--;w--;
    int j=0;
    for(int i=2;i<=w;i++)
    {
        while(j>0&&b[i]!=b[j+1])j=pos[j];
        if(b[j+1]==b[i])j++;
        pos[i]=j;
    }
//  for(int i=1;i<=w;i++)cout<<pos[i]<<" ";cout<<endl;
    j=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        while(j>0&&a[i]!=b[j+1])j=pos[j];
        if(a[i]==b[j+1])j++;
        if(j==w)
        {
            ans++;
            j=pos[j];
        }
    }
    cout<<ans;
    return 0;
}