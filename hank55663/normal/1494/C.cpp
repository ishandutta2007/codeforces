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
    int a[200005];
    int b[200005];
    a[n]=2e9;
    b[m]=2e9;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    set<int> s;
    for(int i = 0;i<m;i++){
        scanf("%d",&b[i]);
     
    }
    int ans=0;
    for(int t=0;t<2;t++){
        s.clear();
        for(int i = 0;i<m;i++)s.insert(b[i]);
        int sum=0;
        int Max=0;
        for(int i = 0;i<n;i++){
            if(a[i]>0&&s.find(a[i])!=s.end()){
                sum++;
            }
        }
        Max=sum;
        int r=-1;
        for(int i = 0;i<m;i++){
            if(b[i]>0){
                r=i+1;
                break;
            }
        }
        int r2=-1;
        for(int i=0;i<n;i++){
            if(a[i]>0){
                r2=i;
                if(s.find(a[i])!=s.end())sum--;
                break;
            }
        }
        if(r!=-1&&r2!=-1){
            int tot=1;
            int st=r2;
            for(int j = r-1;j<m;j++){
                if(b[j]<a[st])continue;
                while(a[r2+1]<=tot+b[j]){
                    tot++;
                    r2++;
                   // printf("?\n");
                    if(s.find(a[r2])!=s.end())sum--;
                }
                while(b[r]<=tot+b[j]-1){
                    r++;
                }
              //  printf("%d %d %d %d\n",j,r,tot,r2);
                Max=max(Max,r-j+sum);
            }
          //  printf("%d\n",Max);
            ans+=Max;
        }
        for(int i=0;i<n;i++)a[i]=-a[i];
        reverse(a,a+n);
        for(int i=0;i<m;i++)b[i]=-b[i];
        reverse(b,b+m);
    }
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/