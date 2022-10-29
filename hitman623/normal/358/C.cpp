#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    vl v[100005],a;
    long n,t,cur=0,b1,b2,b3,f1,f2,f3,i,j,m;
    cin>>n;
    while(n--)
    {
        cin>>t;
        m=t;
        if(t==0)
        cur++;
        else v[cur].pb(t);
    }
    if(m!=0) cur++;
    for(i=0;i<cur;++i)
    {
        b1=0,b2=0,b3=0;
        f1=0,f2=0,f3=0;
        a=v[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        if(a.size()>0)
        b1=a[0];
        if(a.size()>1)
        b2=a[1];
        if(a.size()>2)
        b3=a[2];
        for(j=0;j<v[i].size();++j)
        if(v[i][j]==b1 && f1==0) cout<<"pushStack"<<endl,f1=1;
        else if(v[i][j]==b2 && f2==0) cout<<"pushQueue"<<endl,f2=1;
        else if(v[i][j]==b3 && f3==0) cout<<"pushFront"<<endl,f3=1;
        else cout<<"pushBack"<<endl;
        if(i==cur-1 && m!=0) break;
        cout<<f1+f2+f3;
        if(f1) cout<<" popStack";
        if(f2) cout<<" popQueue";
        if(f3) cout<<" popFront";
        cout<<endl;
    }
    return 0;
}