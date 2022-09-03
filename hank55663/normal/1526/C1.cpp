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
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    priority_queue<int> pq;
    LL sum=0;
    LL ans=n;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x>=0)sum+=x;
        else{
            sum+=x;
            pq.push(-x);
            if(sum<0){
                ans--;
                sum+=pq.top();
                pq.pop();
            }
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--)
        solve();
}
/*
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/