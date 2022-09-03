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
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
bool solve(){
    int n;
    scanf("%d",&n);
    int a[55];
    LL tot[2]={0,0};
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
        tot[i%2]+=a[i]-1;
    }
    if(tot[0]<tot[1]){
        for(int i = 0;i<n;i++){
            if(i%2==0)printf("1 ");
            else printf("%d ",a[i]);
        }
        printf("\n");
    }
    else{

        for(int i = 0;i<n;i++){
            if(i%2==1)printf("1 ");
            else printf("%d ",a[i]);
        }
        printf("\n");
    }
    return true;
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
}