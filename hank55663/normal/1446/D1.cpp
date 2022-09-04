#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[200005];
int cnt[200005][105];
bool check(int l,int r,int target){
    int cntt=0;
    for(int j = 1;j<=100;j++){
        if(cnt[r][j]-cnt[l-1][j]>target)return true;
        if(cnt[r][j]-cnt[l-1][j]==target)cntt++;
    }
    if(cntt>=2)return true;
    return false;
}
int pool[400005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 1;i<=n;i++){
        //a[i]=rand()%2;
        //if(a[i]==0)a[i]=rand()%99+2;
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
        for(int j =0;j<=100;j++){
            cnt[i][j]=cnt[i-1][j];
        }
        cnt[i][a[i]]++;
    }
    int Max=0,Maxi,cnt=0;
    for(int i = 1;i<=n;i++){
        if(Max<v[i].size()){
            Max=v[i].size();
            Maxi=i;
            cnt=1;
        }
        else if(Max==v[i].size())cnt++;
    }
    if(cnt>1){
        printf("%d\n",n);
    }
    else{
        fill(pool,pool+400005,-1);
        int ans=0;
        for(int i = 1;i<=100;i++){
            if(i!=Maxi){
                int *val=pool+200000;
                int sum=0;
                val[0]=0;
                for(int j=1;j<=n;j++){
                    if(a[j]==Maxi)sum++;
                    else if(a[j]==i)sum--;
                    if(val[sum]!=-1){
                    ans=max(ans,j-val[sum]);
                    }
                    else{
                        val[sum]=j;
                    }
                }
                sum=0;
                for(int j=1;j<=n;j++){
                    if(a[j]==Maxi)sum++;
                    else if(a[j]==i)sum--;
                    val[sum]=-1;
                }
            }
        }
        printf("%d\n",ans);
    }
}

int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}