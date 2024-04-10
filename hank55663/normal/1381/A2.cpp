#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
//#define ll long long
void solve(){
    int n;
    scanf("%d",&n);
    char a[100005],b[100005];
    scanf("%s %s",a,b);
    vector<int> v;
    int cnt=0;
    int l=0,r=n-1;
    for(int i = n-1;i>=0;i--){
        if(cnt&1){
            if(b[i]!=a[r]){
                v.pb(1);
            }
            v.pb(i+1);
            r--;
        }
        else{
            if(b[i]==a[l]){
                v.pb(1);
            }
            v.pb(i+1);
            l++;
        }
        cnt++;
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d ",it);
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    //Find();
    while(t--){
        solve();
    }
}