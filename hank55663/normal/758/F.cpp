#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
//vector<short> v[10000005];
bool mygcd[4005][4005];
int main(){
    LL n,l,r;
    scanf("%lld %lld %lld",&n,&l,&r);
    if(n==1){
        printf("%lld\n",(r-l+1));
    }
    else if(n==2){
        printf("%lld\n",(r-l+1)*(r-l));
    }
    else if(n>=25){
        printf("0\n");
    }
    else{
        LL po[100005];
        for(int i = 1;;i++){
            LL tmp=1;
            for(int j = 1;j<n;j++){
                tmp*=i;
                if(tmp>r)tmp=r+1;
            }
            po[i]=tmp;
            if(tmp>r)break;
 //           for(int j = tmp;j<=r;j+=tmp)
  //              v[j].pb(i);
        }
        for(int i =2;i<4005;i++){
            for(int j = i;j<4005;j+=i){
                for(int k = i;k<4005;k+=i){
                    mygcd[j][k]=1;
                }
            }
        }
        int ans=0;
        for(int i = 1;;i++){
            if(po[i]>r)break;
            for(int j = po[i];j<=r;j+=po[i]){
                for(int k = 1;j/po[i]*po[k]<=r;k++){
                    if(j>=l&&j/po[i]*po[k]>=l&&!mygcd[i][k]){
                       // printf("%d %lld\n",j,j/po[i]*po[k]);
                        ans++;
                    }
                }
            }
        }

        /*for(int i = l;i<=r;i++){
            vector<int> tmp;
            for(auto it:v[i]){
                for(int j = 1;i/po[it]*po[j]<=r;j++){
                    if(i/po[it]*po[j]>=l&&mygcd[it][j]==0){
                        ans++;
                        //printf("%d %d %lld\n",i,it,i/it*po[j]);
                    }
                }
            }
        }*/
        printf("%lld\n",ans-(r-l+1));
    }
    return 0;
}
/*
1 
2 6 
3 5 
4
*/