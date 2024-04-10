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
    int a[4];
    for(int i = 0;i<4;i++)scanf("%d",&a[i]);
    vector<int> v;
    v.pb(max(a[0],a[1]));
    v.pb(max(a[2],a[3]));
    sort(a,a+4);
    sort(v.begin(),v.end());
    if(v[0]==a[2]&&v[1]==a[3])printf("YES\n");
    else printf("NO\n");
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