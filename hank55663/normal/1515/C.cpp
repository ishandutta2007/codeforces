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
#define MAXK 2500
//set<int> s;
    vector<int> ans[100005];
void solve(){
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);
    for(int i = 0;i<m;i++)ans[i].clear();
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    for(int i = 0;i<m;i++)pq.push(mp(0,i));
    int a[100005],ans[100005];
    printf("YES\n");
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        pii p=pq.top();
        pq.pop();
        printf("%d ",p.y+1);
        p.x+=a[i];
        pq.push(p);
    }
    printf("\n");
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36

x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/