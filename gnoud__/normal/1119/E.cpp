#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
const int N=300010;
int n,kq,rac,x,c,Pair;
main()
{
    ios_base::sync_with_stdio(false);
    //freopen("a.inp", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin>>n;
    forinc(i,1,n)
    {
        cin>>x;
        rac+=x%2;
        Pair=x/2;
        c=max(0ll,(Pair-rac+2)/3);
        rac+=c*3-Pair;
        kq+=Pair-c;
    }
    cout<<kq;
}