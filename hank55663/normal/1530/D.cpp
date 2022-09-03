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
static const double INF = 2147483647;
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int b[200005];
    int match[200005];
    fill(match,match+n+1,-1);
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    vector<int> v1,v2;
    for(int i = 1;i<=n;i++){
        if(match[a[i]]==-1){
            match[a[i]]=i;
            b[i]=a[i];
        }
        else{
            v1.pb(i);
        }
    }
    for(int i = 1;i<=n;i++){
        if(match[i]==-1)v2.pb(i);
    }
    if(v1.size()==1){
        if(v1[0]==v2[0]){
            b[v1[0]]=a[v1[0]];
            b[match[a[v1[0]]]]=v1[0];
        }
        else{
            b[v1[0]]=v2[0];
        }
    }
    else if(v1.size()){
        deque<int> q;
        for(auto it:v2)q.pb(it);
        for(auto it:v1){
            if(q.front()==it)b[it]=q.back(),q.pop_back();
            else b[it]=q.front(),q.pop_front();
        }
        if(b[v1.back()]==v1.back()){
            swap(b[v1.back()],b[v1[0]]);
        }
    }
    printf("%d\n",n-v1.size());
    for(int i = 1;i<=n;i++)printf("%d ",b[i]);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}