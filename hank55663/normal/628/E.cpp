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
int lcnt[3005][3005];
int rcnt[3005][3005];
int S[3005];
char c[3005][3005];
void add(int x,int k){
    for(int i = x;i<3005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i =x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j =1;j<=m;j++){
            if(c[i][j]=='z')lcnt[i][j]=lcnt[i][j-1]+1;
            else lcnt[i][j]=0;
        }
        for(int j=m;j>=1;j--){
            if(c[i][j]=='z')rcnt[i][j]=rcnt[i][j+1]+1;
            else rcnt[i][j]=0;
        }
    }
    LL res=0;
    for(int i = 1;i<=n+m;i++){
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int j=1;j<=n;j++){
            if(i-j>m)continue;
            if(i-j<=0)break;
            if(c[j][i-j]=='z'){
                add(j,1);
                pq.push(mp(lcnt[j][i-j]+j,j));
                //printf("%d %d\n",lcnt[j][i-j]+j,j);
                while(!pq.empty()&&pq.top().x==j){
                    add(pq.top().y,-1);
                    //printf("!%d\n",pq.top().y);
                    pq.pop();
                }
                res+=query(j)-query(j-rcnt[j][i-j]);
              //  printf("%d %d %d\n",j,i-j,query(j)-query(j-rcnt[j][i-j]));
            }
            else{
                while(!pq.empty()){
                    add(pq.top().y,-1);
                    pq.pop();
                }
            }
        }
        while(!pq.empty()){
            add(pq.top().y,-1);
            pq.pop();
        }
    }
    printf("%lld\n",res);
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