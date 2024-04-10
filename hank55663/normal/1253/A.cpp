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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
#define N 100005
void solve(){
     int n;
        scanf("%d",&n);
        int a[100005];
        int b[100005];
        for(int i = 0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
            b[i]-=a[i];
        }
        int l=-1,r=-2,cnt=0,num=0;
        for(int i = 0;i<n;i++){
            if(b[i]!=0){
                if(b[i]<0){
                    printf("NO\n");
                    return ;   
                }
                if(num==0)num=b[i];
                if(b[i]!=num){
                    printf("NO\n");
                    return ;
                }
                cnt++;
                if(l==-1)l=i;
                r=i;
            }
        }
        if(cnt!=r-l+1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}