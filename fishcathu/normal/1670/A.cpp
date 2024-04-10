#include<bits/stdc++.h>
using namespace std;
const int N=1E5+10;
template<typename T=int>T read(){T x;cin>>x;return x;}

int a[N];
void solve()
{
    int n=read();
    for(int i=1,j=0;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]<0)a[i]*=-1,a[++j]*=-1;
    }
    cout<<(is_sorted(a+1,a+1+n)?"YES":"NO")<<'\n';
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int T=read();T--;solve());
}