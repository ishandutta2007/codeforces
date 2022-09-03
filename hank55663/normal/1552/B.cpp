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
    int n;
    scanf("%d",&n);
    int a[50005][5];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int Maxi=0;
    for(int i = 1;i<n;i++){
        int cnt=0;
        for(int j = 0;j<5;j++){
            if(a[i][j]>a[Maxi][j])cnt++;
        }
        if(cnt<3)Maxi=i;
    }
    int ok=1;
    for(int i = 0;i<n;i++){
        if(i==Maxi)continue;
        int cnt=0;
        for(int j = 0;j<5;j++){
            if(a[i][j]>a[Maxi][j])cnt++;
        }
        if(cnt<3)ok=0;
    }
    if(ok)printf("%d\n",Maxi+1);
    else printf("-1\n");
    return;
    for(int i = 0;i<5;i++){
        int Max=1e9,Maxi;
        for(int j = 0;j<n;j++){
            if(a[j][i]<Max){
                Max=a[j][i];
                Maxi=j;
            }
        }
        int ok=1;
        for(int j = 0;j<n;j++){
            if(j==Maxi)continue;
            int cnt=0;
            for(int k = 0;k<5;k++){
                if(a[j][k]>a[Maxi][k])cnt++;
            }
            if(cnt<3)ok=0;
        }
        if(ok){
            printf("%d\n",Maxi+1);
            return;
        }
    }
    printf("-1\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
0 1 1 1
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
x^2+y^2=kxy+k;
64+y^2=32y+4;
y^2-32y+60=0;

x^2-k*y*x-k+y*y=0;
a=1;
b=-k*y;
c=y*y-k
x=ky+-sqrt(k*k*y*y+4*k-4*y*y) 
*/