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
    int n;
    scanf("%d",&n);
    int Min=1e9;
    int a[100005],b[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
        Min=min(Min,b[i]);
    }
    sort(b+1,b+n+1);
    for(int i = 1;i<=n;i++){
        if(__gcd(a[i],Min)!=Min){
            if(a[i]!=b[i]){
                printf("NO\n");
                return ;
            }
        }
    }
    printf("YES\n");
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