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

void solve(int T){
   int n,m;
   scanf("%d %d",&n,&m);
   pii p[10];
   for(int j = 0;j<m;j++){
    scanf("%d %d",&p[j].x,&p[j].y);
   } 
   if(m>n){
    printf("No\n");
   }
   else{
        int cnt=0,Max=0;
        for(int j=0;j<m;j++){
            int tot=0;
            for(int k = 0;k<m;k++){
                if(j==k)continue;
                if(p[j].x==p[k].x||p[j].y==p[k].y){
                    tot++;
                    cnt++;
                }
            }
            Max=max(Max,tot);
        }
        if(n==m&&Max==0){
            printf("No\n");
        }
        else if(Max==cnt/2){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
   }
}

int main(){
  //  srand(time(NULL));
    int t=1;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*575855273
1
2 4
3 
5
*/