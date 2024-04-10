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
const int mod=1e9+7;
void solve(){
    int a[2005];
    int n;
    scanf("%d",&n);
    vector<int> v[2];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        v[a[i]%2].pb(a[i]);
    }
    int ans=n*(n-1)/2;
    for(int i = 0;i<v[1].size();i++){
        for(int j=i+1;j<v[1].size();j++){
            if(__gcd(v[1][i],v[1][j])==1)ans--;
        }
    }
    printf("%d\n",ans);
} 
/*
C[n-(k-1)*(i-1)][n-i-(k-1)*(i+1)]
//[n-k*i+i-k+1][i]
*/
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/