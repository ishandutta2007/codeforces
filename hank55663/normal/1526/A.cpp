#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int a[55];
    for(int i = 0;i<2*n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+2*n);
    vector<int> v;
    for(int i = 0;i<n;i++){
        v.pb(a[i]);
        v.pb(a[2*n-i-1]);
    }
    for(auto it:v){
        printf("%d ",it);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/