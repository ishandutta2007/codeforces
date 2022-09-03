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
vector<int> v[200005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<=n;i++)v[i].clear();
    for(int i = n-1;i>=0;i--)v[a[i]].pb(i);
    vector<int> b;
    int now=0;
    while(now!=n){
        int l=now;
        for(int i = 0;i<=n;i++){
            while(v[i].size()&&v[i].back()<l)v[i].pop_back();
            if(v[i].empty()){
                if(i==0)b.pb(0),now++;
                else b.pb(i),now++;
                break;
            }
            else{
                now=max(now,v[i].back());
                v[i].pop_back();
            }
        }
        //printf("%d %d\n",l,now);
    }
    printf("%d\n",b.size());
    for(auto it:b)printf("%d ",it);
    printf("\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}