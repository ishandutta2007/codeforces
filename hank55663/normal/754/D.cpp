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
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    pair<pii,int> p[300005];
    vector<pii> v;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(mp(x,y+1),i+1);
    }
    sort(p,p+n);
    priority_queue<int,vector<int>,greater<int> > pq;
    int ans=0,ansx=0,ansy=k;
    for(int i = 0;i<k-1;i++){
        pq.push(p[i].x.y);
    }
    for(int i = k-1;i<n;i++){
        pq.push(p[i].x.y);
        if(pq.top()-p[i].x.x>ans){
            ans=pq.top()-p[i].x.x;
            ansx=p[i].x.x;
            ansy=pq.top();
        }
        pq.pop();
    }
    printf("%d\n",ans);
    if(ans==0){
        for(int i = 1;i<=k;i++)
        printf("%d ",i);
        printf("\n");
    }
    else{
        for(int i = 0;i<n;i++){
            if(p[i].x.x<=ansx&&p[i].x.y>=ansy){
                printf("%d ",p[i].y);
                k--;
            }
            if(k==0)
            return 0;
        }
    }
}
/*
1 
2 6 
3 5 
4
*/