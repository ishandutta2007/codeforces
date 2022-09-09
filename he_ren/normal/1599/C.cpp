#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)((x).size()))
#define lb(x) ((x)&(-(x)))
#define mkp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
long double eps=1e-9;

inline ll C(int n,int m)
{
    if(n<m) return 0ll;
    ll res=1;
    for(int i=n;i>=n-m+1;i--) res=res*i;
    for(int i=1;i<=m;i++) res/=i;
    return res;
}

int n; double p;
inline long double chk(int x)
{
    ll all=C(n,3);
    long double p1=(long double)C(n-x,2)*C(x,1)/all*0.5;
    long double p2=(long double)C(n-x,1)*C(x,2)/all;
    long double p3=(long double)C(n-x,0)*C(x,3)/all;

//    printf("p1 = %.3Lf , p2 = %.3Lf , p3 = %.3Lf\n")
    return p1+p2+p3;
}

void solve()
{
    scanf("%d%lf",&n,&p);
    if(p<=eps)
    {
        puts("0");
        return ;
    }
    for(int i=1;i<=n;i++)
        if(chk(i)>=p-eps)
        {
            printf("%d\n",i);
            return ;
        }
}

int main()
{
	int T=1;
	while(T--) solve();
	return 0;
}