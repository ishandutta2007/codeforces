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
using namespace std;
bool solve(){
    int n;
    scanf("%d",&n);
    int p[405],p2[405];
    MEM(p);
    MEM(p2);
    for(int i = 0;i<n;i++){
        char c;
        int a,b;
        scanf(" %c %d %d",&c,&a,&b);
        if(c=='F')p[a]++,p[b+1]--;
        if(c=='M')p2[a]++,p2[b+1]--;
    }
    int sum1=0,sum2=0;
    int ans=0;
    for(int i = 1;i<=366;i++){
        sum1+=p[i];
        sum2+=p2[i];
        ans=max(ans,min(sum1,sum2));
    }
    printf("%d\n",ans*2);
    return true;
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--)solve();//solve();
}
/*

4 7 2 1 7 4 3 1 7 2
*/