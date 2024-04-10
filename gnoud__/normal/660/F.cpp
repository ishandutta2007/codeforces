#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
#define forv(a,b) for(auto&a:b)
#define pb push_back
#define pp pop_back()
#define db double
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N=200010;
int n,a[N],s1[N],s2[N],top,kq;
int f[N];
void read( int &x)
{
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
vector<pair<int,int >> st;
double giao(pii u,pii v)
{
    return db(db(v.se)-db(u.se))/(db(u.fi)-db(v.fi));
}
main()
{
    //freopen("660F.inp","r",stdin);
    //freopen("660F.out","w",stdout);
    read(n);
    forinc(i,1,n)
    {
        read(a[i]);
        s1[i]=s1[i-1]+a[i];
        s2[i]=s2[i-1]+a[i]*i;
        //cout<<i<<" "<<s1[i]<<" "<<s2[i]<<endl;
    }
    //cout<<endl;
    f[1]=a[1];st.pb({0,0});
    forinc(i,2,n)
    {
        pii O={1-i,(i-1)*s1[i-1]-s2[i-1]};
        while(top>=1&&giao(st[top-1],st[top])<=giao(st[top],O)) {top--;st.pp;}
        ++top;st.pb(O);
        int l=1,r=top,o=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(giao(st[mid],st[mid-1])>s1[i])
            {
                o=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        f[i]=s1[i]*st[o].fi+st[o].se+s2[i];
        /*cout<<i<<" "<<f[i]<<endl;
        {
            cout<<top<<endl;
            forinc(j,0,top) cout<<st[j].fi<<" "<<st[j].se<<endl;
        }
        cout<<endl;*/
    }
    forinc(i,1,n) kq=max(kq,f[i]);
    cout<<kq;
}