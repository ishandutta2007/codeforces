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
void solve(){
    int n,x;
    scanf("%d %d",&n,&x);
    int w[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&w[i]);
    }
    sort(w,w+n);
    reverse(w,w+n);
    priority_queue<int> pq;
    int ans=0;
    pq.push(x);
    ans++;
    for(int i = 0;i<n;i++){
        if(pq.top()<w[i]){
            ans++;
            pq.push(x);
        }
        int t=pq.top();
        pq.pop();
        pq.push(t-w[i]);
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}