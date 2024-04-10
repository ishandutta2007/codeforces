#include<bits/stdc++.h>
using namespace std;
inline long long in()
{
    long long x=0;int c=getchar(),n=0;
    for(;!isdigit(c);c=getchar()) n=(c=='-');
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return n?-x:x;
}
#define ll long long
#define FOR(i,a,b) for(int i(a);i<=b;i++)
#define ROF(i,a,b) for(int i(b);a<=i;i--)
#define VEC(i,a) for(auto&i:a)
#define rr(x) " "<<#x<<'='<<x<<" "
#define mt make_tuple
#define t0(a) get<0>(a)
#define t1(a) get<1>(a)
#define pb push_back

#define int ll
const int N=1e5+5;
int n;
int d[10][10];
int CAL(int x,int y,int step)
{

    d[x][y]=1;
    cout<<char(y+'a'-1)<<x<<" ";

    if(step==0) return 0;
    if(step==2)
    {
        if(y==8) return CAL(x+1,y,step-1);
        if(x<8) return CAL(8,y,step-1);
    }
    if(step==1) return CAL(8,8,step-1);
    ROF(j,1,8) if(!(step==3&&x==7&&j==8)) if(!(x==8&&j==8)) if(!d[x][j]) return CAL(x,j,step-1);
    return CAL(x+1,y,step-1);
}
main()
{
   // freopen("42.inp","r",stdin);
    n=in();
    CAL(1,1,n);
}