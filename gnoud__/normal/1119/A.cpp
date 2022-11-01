#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
const int N=300010;
int n,f[N],kq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    forinc(i,1,n)
    {
        int x;cin>>x;
        if(i==f[x]+1) f[x]=i;
        else kq=max(kq,i-f[x]-1);
    }
    cout<<kq;
}