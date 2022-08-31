#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,c1,c2,c3,a1,a2,a3,a4,a5;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&c1,&c2,&c3);
        scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
        c1-=a1; c2-=a2; c3-=a3;
        if(c1<0||c2<0||c3<0) {puts("NO"); continue;}
        a4-=min(a4,c1); a5-=min(a5,c2);
        if(c3>=a4+a5) puts("YES"); else puts("NO");
    }
    return 0;
}