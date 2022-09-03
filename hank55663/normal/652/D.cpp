#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int S[400005];
void add(int x,int k){
    for(int i = x;i<400005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
bool cmp(const pair<pii,int> &p,const pair<pii,int> &q){
    return p.x.y<q.x.y;
}
int main(){
    int n;
    scanf("%d",&n);
    map<int,int> m;
    pair<pii,int> p[200005];
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(mp(x,y),i);
        m[x];
        m[y];
    }
    int index=0;
    for(auto &it:m)it.y=++index;
    for(int i = 0;i<n;i++){
        p[i].x.x=m[p[i].x.x];
        p[i].x.y=m[p[i].x.y];
    }
    sort(p,p+n,cmp);
    int ans[200005];
    for(int i = 0;i<n;i++){
        ans[p[i].y]=query(p[i].x.y)-query(p[i].x.x);
        add(p[i].x.x,1);
    }
    for(int i = 0;i<n;i++){
        printf("%d\n",ans[i]);
    }
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/