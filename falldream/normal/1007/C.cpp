#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
ll l1=1,l2=1,r1,r2,m1,m2;
int Ask(ll a,ll b)
{
    printf("%lld %lld\n",a,b);fflush(stdout);
    int x=read();
    if(!x) exit(0);
    return x;
}
int main()
{
    scanf("%lld",&r1);m1=m2=r2=r1;
    while(1)
    {
        ll X=l1,Y=l2,l=l1,r=m1,mid;
        ld S=(ld)(m1-l1+1)*(r2-l2+1)+(ld)(r1-m1)*(m2-l2+1);
        while(l<=r)
        {
            mid=l+r>>1;
            ld nowS=(ld)(mid-l1+1)*(r2-l2+1);
            if(nowS*3<=S) X=mid,l=mid+1;
            else r=mid-1;
        }
        l=l2,r=m2;
        while(l<=r)
        {
            mid=l+r>>1;
            ld nowS=(ld)(mid-l2+1)*(r1-l1+1);
            if(nowS*3<=S) Y=mid,l=mid+1;
            else r=mid-1;
        }
        //cout<<"now"<<l1<<" "<<m1<<" "<<r1<<" "<<l2<<" "<<m2<<" "<<r2<<" "<<X<<" "<<Y<<" "<<S<<endl;
        //if(m1<l1||m2<l2) return 0;
        int stat=Ask(X,Y);
        if(stat==1) l1=X+1;
        if(stat==2) l2=Y+1;
        if(stat==3) m1=X-1,m2=Y-1;
        if(m1<l1) r2=m2,m1=r1;
        if(m2<l2) r1=m1,m2=r2;
    }
    return 0;
}