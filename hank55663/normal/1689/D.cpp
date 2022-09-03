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
#define index Index
char c[1005][1005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pii> v;
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        for(int j = 0;j<m;j++){
            if(c[i][j]=='B'){
                v.pb(mp(i+1+j+1,i-j));
            }
        }
    }
    int Min=-1,Max=2005;
    while(Min+1<Max){
        int mid=(Max+Min)/2;
        int lx=-2000,rx=2000,ly=-2000,ry=2000;
        for(auto it:v){
            lx=max(lx,it.x-mid);
            rx=min(rx,it.x+mid);
            ly=max(ly,it.y-mid);
            ry=min(ry,it.y+mid);
        }
        if(lx<=rx&&ly<=ry){
            Max=mid;
        }
        else {
            Min=mid;
        }
    }
    int lx=-2000,rx=2000,ly=-2000,ry=2000;
    for(auto it:v){
        lx=max(lx,it.x-Max);
        rx=min(rx,it.x+Max);
        ly=max(ly,it.y-Max);
        ry=min(ry,it.y+Max);
    }
    //printf("%d %d %d %d %d\n",lx,rx,ly,ry,Max);
    for(int i = lx;i<=rx;i++){
        for(int j=ly;j<=ry;j++){
            if((i+j)%2==0&&(i+j)/2>=1&&(i+j)/2<=n&&(i-j)/2>=1&&(i-j)/2<=m){
                printf("%d %d\n",(i+j)/2,(i-j)/2);
                return;
            }
        }
    }
    Max++;
    lx=-2000,rx=2000,ly=-2000,ry=2000;
    for(auto it:v){
        lx=max(lx,it.x-Max);
        rx=min(rx,it.x+Max);
        ly=max(ly,it.y-Max);
        ry=min(ry,it.y+Max);
    }
    //printf("%d %d %d %d %d\n",lx,rx,ly,ry,Max);
    for(int i = lx;i<=rx;i++){
        for(int j=ly;j<=ry;j++){
            if((i+j)%2==0&&(i+j)/2>=1&&(i+j)/2<=n&&(i-j)/2>=1&&(i-j)/2<=m){
                printf("%d %d\n",(i+j)/2,(i-j)/2);
                return;
            }
        }
    }
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}