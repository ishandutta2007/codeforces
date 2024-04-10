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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v;
    for(int i = k+1;i<=n;i++)v.pb(i);
    for(int i = (k+1)/2;i<k;i++)v.pb(i);
    printf("%d\n",v.size());
    
    for(auto it:v)printf("%d ",it);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
5
4 3
1 4
4 2
3 4
0 0
*/