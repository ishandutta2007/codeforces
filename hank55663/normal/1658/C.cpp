#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
#define MXN 200005
int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    vector<int> v;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1)v.pb(i);
    }
    if(v.size()!=1){
        printf("No\n");
    }
    else{
        int last=1;
        for(int i = v[0]%n+1;i!=v[0];i=i%n+1){
            if(a[i]>last+1){
                printf("No\n");
                return;
            }
            last=a[i];
        }
        printf("Yes\n");
    }
}  
 
 
int main(){
    int t=1;0000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
 
*/