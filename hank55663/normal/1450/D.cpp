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
using namespace std;
#define MXN 100005
int cnt[300005];
bool solve(){
    int n;
    scanf("%d",&n);
    int a[300005];
    fill(cnt,cnt+n+1,0);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    vector<int> v;
    int ok=1;
    int l=1,r=n;
    for(int i = 1;i<n;i++){
        if(!cnt[i]||!ok){
            v.pb(0);
        }
        else{
            v.pb(1);
        }
        if(a[l]==i&&cnt[i]==1){
            l++;
        }
        else if(a[r]==i&&cnt[i]==1){
            r--;
        }
        else{
            ok=0;
        }
    }
    
    sort(a+1,a+n+1);
    ok=1;
    for(int i = 1;i<=n;i++){
        if(a[i]!=i)ok=0;
    }
    v.pb(ok);
    reverse(v.begin(),v.end());
    for(auto it:v){
        printf("%d",it);
    }
    printf("\n");
    return true;
}
int main(){
    int t=1;   scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}
/*

2 3
1 3
4 2
2 5
3 5
1 2
5 4
*/