#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
#define MXN 200005
int cnt[200005];
int cc[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int tot=0;
    for(int i = 1;i<=n;i++){
        char c;
        scanf(" %c",&c);
        cc[i]=c-'0';
        //scanf("%d",&cc[i]);
        tot+=cc[i];
    }
    if(tot*1ll*m%n!=0){
        printf("-1\n");
    }
    else{
        int need=tot*1ll*m/n;
        for(int i = 1;i<=n;i++)cnt[i]=cnt[i-1]+cc[i];
        int a=-1,b=-1;
        for(int i = m;i<=n;i++){
            if(cnt[i]-cnt[i-m]==need){
                printf("1\n");
                printf("%d %d\n",i-m+1,i);
                return;
            }
            else if(cnt[i]-cnt[i-m]>need){
                a=i;
            }
            else{
                b=i;
            }
        }
       // printf("%d %d\n",a,b);
        if(a!=-1&&b!=-1){
            if(a>b)swap(a,b);
            int l1=a-m+1,r1=l1-1;
            int l2=b-m+1,r2=b;
            int tot=cnt[r2]-cnt[l2];
            while(tot!=need){
                r1++;
                tot+=cc[r1];
                tot-=cc[l2];
                l2++;
            }
              printf("2\n");
        printf("%d %d\n%d %d\n",l1,r1,l2,r2);
        }
        else{
            int a=-1,b=-1;
            m=n-m;
            need=tot-need;
            for(int i = m;i<=n;i++){
                if(cnt[i]-cnt[i-m]==need){
                    printf("2\n");
                    printf("%d %d\n%d %d\n",1,i-m,i+1,n);
                    return;
                }
                else if(cnt[i]-cnt[i-m]>need){
                    a=i;
                }
                else{
                    b=i;
                }
            }
            if(a>b)swap(a,b);
            int l1=a-m+1,r1=l1-1;
            int l2=b-m+1,r2=b;
            int tot=cnt[r2]-cnt[l2];
            while(tot!=need){
                r1++;
                tot+=cc[r1];
                tot-=cc[l2];
                l2++;
            }
              printf("2\n");
        printf("%d %d\n%d %d\n",1,l1-1,r1+1,l2-1);
        }
      
    }
}  
 
 
int main(){
    int t=1;0000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
 
*/