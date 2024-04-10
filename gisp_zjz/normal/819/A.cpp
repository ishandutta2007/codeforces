#include<bits/stdc++.h>
#define maxn 234050
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
int a,b,c,d,r,h[150],p,t,ans;
bool f[30];

int main()
{
    cin>>a>>b>>c>>d; r=a+b;
    for (int i=1;i<=a;i++) h[i]=i;
    for (int i=1;i<=b;i++) h[a+i]=a;
    for (int i=1;i<=b;i++) h[r+i]=i;
    for (int i=1;i<=a;i++) h[r+b+i]=a+i;
    for (int i=1;i<=b;i++) h[r+a+i]=h[r+a];
    if(b>=a) for (int i=r+a;i<=r+r;i++) h[i]++;
    r*=2;
    d=min(d,c+r);
    for (int i=c;i<=d;i++)
    {
        t=h[(i-1)%r+1];
        if (!f[t]) p++; f[t]=true;
    }
    ans=p;p=0;memset(f,0,sizeof(f));
    if (a-b>1&&d-c+1>a+b){
        for (int j=1;j<=b;j++) h[a+j]=h[b+1];
        for (int j=1;j<=a;j++){
            int k=0;
            while(1){
                k++; bool flag=true;
                for (int i=b+1;i<a+b+j;i++) if (h[i]==k)flag=false;
                if (flag) break;
            }
            h[a+b+j]=k;
        }
        for (int j=1;j<=b;j++) h[a+a+b+j]=h[a+b+b+1];
    }
    for (int i=c;i<=d;i++)
    {
        t=h[(i-1)%r+1];
        if (!f[t]) p++; f[t]=true;
    }
    cout<<min(p,ans)<<endl;
}