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
    int n,k;
    scanf("%d %d",&n,&k);
    if(k<n&&k%2!=n%2){
        printf("1\n");
    }
    else
    printf("%d\n",max(0,k-n));
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