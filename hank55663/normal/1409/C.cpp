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

void solve(){   
int n,x,y;
scanf("%d %d %d",&n,&x,&y);
int d=y-x;
for(int i = 1;i<=d;i++){
    if(d%i==0){
        if(d/i+1<=n){
            deque<int> q;
            q.push_back(x);
            int now=x;
            while(now!=y){
                now+=i;
                q.push_back(now);
            }
            now=x-i;
            while(q.size()<n&&now>0){
                q.push_front(now);
                now-=i;
            }
            now=y+i;
            while(q.size()<n){
                q.push_back(now);
                now+=i;
            }
            while(q.size()){
                printf("%d ",q.front());
                q.pop_front();
            }
            printf("\n");
            return ;
        }
    }
}
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/