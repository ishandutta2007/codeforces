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
    priority_queue<int,vector<int>,greater<int> > pq;
    int cnt=1e9;
    int tot=0;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x>=0){
            cnt++;
        }
        else{
            pq.push(cnt);
            cnt=0;
            tot++;
        }
    }
    if(tot>k){
        printf("-1\n");
        //tot-=k;
        return 0;
    }
    if(pq.empty()){
        printf("0\n");
        return 0;
    }
    k-=tot;
    while(pq.top()<=k){
        k-=pq.top();
        pq.pop();
    }
    if(k>=cnt){
        printf("%d\n",pq.size()*2-1);
    }
    else{
        printf("%d\n",pq.size()*2);
    }
}