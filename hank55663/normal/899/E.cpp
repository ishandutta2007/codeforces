#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define next Next
int main(){
    int n;
    scanf("%d",&n);
    vector<pii> v;
    //v.pb(mp(-1,0));
    int last=-1;
    int cnt=0;
    for(int i =0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x!=last){
            v.pb(mp(last,cnt));
            last=x;
            cnt=0;
        }
        cnt++;
    }
    v.pb(mp(last,cnt));
    v.pb(mp(-2,0));
    #define last Last
    vector<int> next,last,ok;
    priority_queue<pii> pq;
    for(int i = 0;i<v.size();i++){
        next.pb(i+1),last.pb(i-1),ok.pb(1);
        if(i!=0&&i!=v.size()-1){
            pq.push(mp(v[i].y,-i));
        }
    }
    int ans=0;
    while(!pq.empty()){
        pii p =pq.top();
        pq.pop();
        if(!ok[-p.y])continue;
        ans++;
     //  printf("%d %d %d\n",-p.y,p.x,v[-p.y].x);
        ok[-p.y]=0;
        p.y=-p.y;
        last[next[p.y]]=last[p.y];
        next[last[p.y]]=next[p.y];
     //   printf("%d %d\n",v[next[p.y]].x,v[last[p.y]].x);
      //  printf("%d %d\n",next[p.y],last[p.y]);
        if(v[next[p.y]].x==v[last[p.y]].x){
            v[last[p.y]].y+=v[next[p.y]].y;
            pq.push(mp(v[last[p.y]].y,-last[p.y]));
            next[last[p.y]]=next[next[p.y]];
            last[next[next[p.y]]]=last[p.y];
            ok[next[p.y]]=0;
        }
    }
    printf("%d\n",ans);
}
/*
1 8 18
2 7 17
3 6 16
4 5 15
5 14
6 13
7 12
8 11
9 10
10 19
11 18
12 17
13 16
14 15
0 ~ 2345 2
2346 ~ 9999 1
 9999
12345
*/