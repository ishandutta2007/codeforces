#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
const int N=1e6+10;
int n,a[N],s[N],ma;
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("a.inp","r",stdin);
    cin>>n;
    int kq=0,o=0;
    forinc(i,1,n) cin>>a[i],ma=max(ma,a[i]);
    forinc(i,1,n)
    {
        if(a[i]==ma) o++;
        else o=0;
        kq=max(kq,o);
    }
    cout<<kq;
}