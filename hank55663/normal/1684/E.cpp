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
#define index Index
#define MXN 10000
const int mod=998244353;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[100005];
    int val[100005];
    map<int,int> m;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    sort(a,a+n);
    for(int i = 0;i<n;i++){
        if(i==n-1||a[i]!=a[i+1]){
            val[i]=m[a[i]];
        }
    }
    int need=0;
   // int now=0;
    int ans=m.size();
    int now=0;
    multiset<int> s1,s2;
    for(auto it:m){
        s2.insert(it.y);
    }
    int sum=0;
    while(s2.size()&&sum+*s2.begin()<=k){
        sum+=*s2.begin();
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
    }
    for(int i =1;i<=n;i++){
        while(now<n&&a[now]<i){
            if(now==n-1||a[now]!=a[now+1]){
                if(s1.find(val[now])!=s1.end()){
                    s1.erase(s1.find(val[now]));
                    sum-=val[now];
                }
                else{
                    s2.erase(s2.find(val[now]));
                }
            }
            now++;
        }
        if(m[i-1]==0)need++;
        if(need>k)break;
        while(s2.size()&&sum+*s2.begin()<=k){
            sum+=*s2.begin();
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
        ans=min(ans,(int)s2.size());
    }
    printf("%d\n",ans);
}
int main(){
   // srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}