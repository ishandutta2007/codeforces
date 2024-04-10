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
const int mod=1e9+7;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int tn=n;
    map<int,int> a;
    for(int i = 2;i<=n;i++){
        while(n%i==0)a[i]++,n/=i;
    }
    n=tn;
    int ansx=1;
    for(auto it:a){
        int t=1;
        int tmpn=n;
        if(it.x==2){
            for(int j=0;j<it.y;j++){
                tmpn/=it.x;
                printf("? %d %d %d %d %d %d\n",tmpn,m,1,1,tmpn+1,1);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                if(x==1){
                    t++;

                }
                else{
                    break;
                }
            }
        }
        else{
            for(int j=0;j<it.y;j++){
                tmpn/=it.x;
                printf("? %d %d %d %d %d %d\n",tmpn,m,1,1,tmpn+1,1);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                printf("? %d %d %d %d %d %d\n",it.x/2*tmpn,m,tmpn+1,1,tmpn+1+it.x/2*tmpn,1);
                fflush(stdout);
                int y;
                scanf("%d",&y);
                if(x&&y){
                    t++;
                }
                else{
                    break;
                }
            }
        }
        ansx*=t;
    }
    int ansy=1;
    a.clear();
    int tm=m;
     for(int i = 2;i<=m;i++){
        while(m%i==0)a[i]++,m/=i;
    }
    m=tm;
    for(auto it:a){
        int t=1;
        int tmpm=m;
        if(it.x==2){
            for(int j=0;j<it.y;j++){
                tmpm/=it.x;
                printf("? %d %d %d %d %d %d\n",n,tmpm,1,1,1,tmpm+1);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                if(x==1){
                    t++;
                }
                else{
                    break;
                }
            }
        }
        else{
            for(int j=0;j<it.y;j++){
                tmpm/=it.x;
                printf("? %d %d %d %d %d %d\n",n,tmpm,1,1,1,1+tmpm);
                fflush(stdout);
                int x;
                scanf("%d",&x);
                printf("? %d %d %d %d %d %d\n",n,it.x/2*tmpm,1,1+tmpm,1,tmpm+it.x/2*tmpm+1);
                fflush(stdout);
                int y;
                scanf("%d",&y);
                if(x&&y){
                    t++;
                }
                else{
                    break;
                }
            }
        }
        ansy*=t;
    }
    printf("! %d\n",ansx*ansy);
    fflush(stdout);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
5
4 3
1 4
4 2
3 4
0 0
*/