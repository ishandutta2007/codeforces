#include<bits/stdc++.h>
using namespace std;
const int N=38730;
template<typename T=int>T read(){T x;cin>>x;return x;}

int a[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    cout<<fixed<<setprecision(6);
    for(int i=1;i<N;++i)a[i]=a[i-1]+(i-(i+2)/3<<1);
    for(int T=read();T--;cout<<lower_bound(a,a+N,read())-a<<'\n');
}