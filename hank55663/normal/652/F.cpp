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
int main(){
    LL n,m,t;
    scanf("%lld %lld %lld",&n,&m,&t);
    pair<pair<int,char>,int>  p[300005];
    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        int x;
        char c;
        scanf("%d %c",&x,&c);
        p[i]=mp(mp(x,c),i);
        if(c=='L'){
            ans.pb(((x-t-1)%m+m)%m+1);
        }
        else{
            ans.pb((x+t-1)%m+1);
        }
    }
    sort(ans.begin(),ans.end());
    sort(p,p+n);
    LL sum=0;
    for(int i = 1;i<n;i++){
        if(p[i].x.y!=p[0].x.y){
            sum+=(2*t)/m;
            if(p[0].x.y=='L'&&p[i].x.y=='R'){
                int dis=(p[0].x.x-p[i].x.x+m)%m;
                if(dis<(2*t)%m)sum++;
            }
            else{
                int dis=(p[i].x.x-p[0].x.x+m)%m;
                if(dis<(2*t)%m)sum++;
            }
            sum%=n;
        }
    }
    //LL loc;
    int res[300005];
    if(p[0].x.y=='L'){
        LL loc=((p[0].x.x-t-1)%m+m)%m+1;
        int num=(n-(sum%n))%n;
        int now;
        for(int i = ans.size()-1;i>=0;i--){
            if(ans[i]==loc){
                now=i;
                break;
            }
        }
        for(int i = 0;i<n;i++){
            res[p[num].y]=ans[now];
            now=(now+1)%n;
            num=(num+1)%n;
        }
            //ans.size();)
    }
    else{
        LL loc=(p[0].x.x+t-1)%m+1;
        int num=sum%n;
        int now=0;
        for(int i = 0;i<ans.size();i++){
            if(ans[i]==loc){
                now=i;
                break;
            }
        }
        for(int i = 0;i<n;i++){
            res[p[num].y]=ans[now];
            now=(now+1)%n;
            num=(num+1)%n;
        }
    }
    for(int i = 0;i<n;i++){
        printf("%d ",res[i]);
    }
    printf("\n");
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