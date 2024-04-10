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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    pii val[5005];
    for(int i = 0;i<m;i++){
        char c[505];
        fill(c,c+m,'0');
        c[m]=0;
        c[i]='1';
        printf("? %s\n",c);
        fflush(stdout);
        scanf("%d",&val[i].x);
        val[i].y=i;
    }
    sort(val,val+m);
    int ans=0;
    char now[505];
    fill(now,now+m,'0');
    now[m]=0;
    for(int i = 0;i<m;i++){
        now[val[i].y]='1';
        printf("? %s\n",now);
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x==ans+val[i].x)ans+=val[i].x;
        else now[val[i].y]='0';
    }
    printf("! %d\n",ans);
} 

int main(){
   
    int t=1;
  // scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
0 1 2 3 4 5 6 7 
0 1 6 7 4 5 2 3
0 3 2 5 4 7 6 1
0 3 6 1 4 7 2 5
0 5 2 7 4 1 6 3
0 5 6 3 4 1 2 7
0 7 2 1 4 3 6 5
0 7 6 5 4 3 2 1
    a=p*1+(1-p)*(1+t2+a)
    a=p+q+q*t2+q*a
    a=(p+q+q*t2)/(1-q)
*/
/*
0 0 0 0
1 2 1 4
1 0 1 0
3 3 3 3
3 1 2 2
4 1 2 1
2 0 2 0

1 4 2 7 5 6 3
*/