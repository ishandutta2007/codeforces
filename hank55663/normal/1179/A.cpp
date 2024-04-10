#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x)
pii ans[200005];
int main(){
    int n,Q;
    scanf("%d %d",&n,&Q);
    deque<int> q;
    int Max=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        q.push_back(x);
        Max=max(Max,x);
    }
    int num=0;
    while(q.front()!=Max){
        int x=q.front();
        q.pop_front();
        int y=q.front();
        q.pop_front();
        ans[++num]=mp(x,y);
        if(x>y){
            q.push_back(y);
            q.push_front(x);
        }
        else{
            q.push_back(x);
            q.push_front(y);
        }
       // printf("%d\n",num);
    }
    int be=q.front();
    q.pop_front();
    vector<int> vv;
    while(!q.empty()){
        vv.pb(q.front());
        q.pop_front();
    }
    
    while(Q--){
        LL x;
        scanf("%lld",&x);
        if(x<=num)
        printf("%d %d\n",ans[x].x,ans[x].y);
        else{
            x-=num;
            x--;
            printf("%d %d\n",be,vv[x%(n-1)]);
        }
    }
}
/*
m3->m2->m->m4
0 1 2 3 453*
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/