#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
void solve(){
    int a,b,c;
    int x,y,z;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
    int ans=min(c,y);
    c-=ans;
    y-=ans;
    ans*=2;
    int Min=min(z,a);
    z-=Min;
    a-=Min;
    Min=min(c,z);
    c-=Min;
    z-=Min;
    ans-=min(z,b)*2;
    printf("%d\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    int T=1;
    while(t--){
        solve();
    }
}