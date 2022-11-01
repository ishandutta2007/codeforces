#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define int long long
using namespace std;
int sl;
int S(int x)
{
    int res=0;
    while(x)
    {
        res+=x%10;
        x/=10;
    }
    return res;
}
int fi(int x)
{
    while(x>9) x/=10;
    return x;
}
int New(int x)
{
    int f=fi(x);
    int y=f-1;
    int o=sl-1;
    if(S(x)==f) o--;
    forinc(i,1,o) y=y*10+9;
    return y;
}
main()
{
    int n;
    cin>>n;
    if(n<=10) {cout<<n;return 0;}
    int x=n/2;sl=log10(n)+1;
    {
        int _x=n+1;
        int _sl=log10(_x)+1;
        if(_sl>sl) {cout<<S(n);return 0;}
    }
    int y=New(n);
    cout<<S(y)+S(n-y);
}