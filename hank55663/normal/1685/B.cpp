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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
#define MXN 10000
void solve(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int tota=a+c+d,totb=b+c+d;
    char cc[200005];
    scanf("%s",cc);
    int aa=0,bb=0;
    for(int i = 0;cc[i]!=0;i++){
        if(cc[i]=='A')aa++;
        else bb++;
    }
    if(tota!=aa||totb!=bb){
        printf("NO\n");
    }
    else{
        int tot=0;
        vector<int> ab,ba;
        int cnt=1;
        for(int i = 1;cc[i]!=0;i++){
            if(cc[i]!=cc[i-1]){
                cnt++;
            }
            else{
                if(cnt%2==1){
                    tot+=cnt/2;
                }
                else{
                    if(cc[i]=='A')ba.pb(cnt/2);
                    else ab.pb(cnt/2);
                }
                cnt=1;
            }
        }

        if(cnt%2==1){
            tot+=cnt/2;
        }
        else{
            if(cc[a+b+2*c+2*d-1]=='A')ba.pb(cnt/2);
            else ab.pb(cnt/2);
        }
      /*  printf("%d\n",tot);
        for(auto it:ab)printf("%d ",it);
        printf("\n");
        for(auto it:ba)printf("%d ",it);
        printf("\n");*/
        sort(ab.begin(),ab.end());
        int sum=0,sum2=0;
        for(auto it:ab){
            if(sum+it>=c){
                sum2+=max(it-(c-sum)-1,0);
                sum=c;
            }
            else{
                sum+=it;
            }
        }
                sort(ba.begin(),ba.end());
       
        for(auto it:ba){
            if(sum2+it>=d){
                sum+=max(it-(d-sum2)-1,0);
                sum2=d;
            }
            else{
                sum2+=it;
            }
        }
        if(sum<=c){
            int add=min(tot,c-sum);
            tot-=add;
            sum+=add;
        }

        if(sum2<=d){
            int add=min(tot,d-sum2);
            tot-=add;
            sum2+=add;
        }
       // printf("%d %d %d\n",sum,sum2,tot);
        if(sum>=c&&sum2>=d){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
int main(){
   // srand(time(NULL));
    int t=1;;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}