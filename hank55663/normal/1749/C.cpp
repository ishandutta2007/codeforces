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
    int n;
    scanf("%d",&n);
    int cnt[105];
    MEM(cnt);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    int Max=0,tot=0,tot2=0;
    for(int i = 1;i<=n;i++){
        if(i==1)tot+=cnt[i];
        else tot2+=cnt[i];
        if(tot2)tot2--;
        else if(tot)tot--;
        else{
            printf("%d\n",i-1);
            return;
        }
        if(tot)tot--;
        else{
            printf("%d\n",i);
            return;
        }
    }
  //  printf("%d\n",Max);
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