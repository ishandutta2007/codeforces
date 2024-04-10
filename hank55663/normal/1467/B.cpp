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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
bool solve(){
    int n;
    scanf("%d",&n);
    int a[300005];
    int val[300005];
    int sum=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=2){
        printf("0\n");
        return true;
    }
    fill(val,val+n+1,0);
    for(int i = 1;i<n-1;i++){
        //val[i]=0;
        if(a[i]>a[i-1]&&a[i]>a[i+1])val[i]=1;
        if(a[i]<a[i-1]&&a[i]<a[i+1])val[i]=1;
        sum+=val[i];
    }
    int ans=sum;
    if(val[1]||val[n-2])ans--;
    for(int i = 1;i<n-1;i++){
        int tmp=sum;
        if(val[i])tmp--;
        if(val[i-1])tmp--;
      //  printf("%d\n",tmp);
        if(val[i+1]){
            if(a[i+1]>a[i-1]&&a[i+1]>a[i+2]);
            else if(a[i+1]<a[i-1]&&a[i+1]<a[i+2]);
            else tmp--;
        }
        else if(i!=n-2){
            if(a[i+1]>a[i-1]&&a[i+1]>a[i+2]) tmp++;
            else if(a[i+1]<a[i-1]&&a[i+1]<a[i+2]) tmp++;
        }
        ans=min(ans,tmp);
        tmp=sum;
        if(val[i])tmp--;
        if(val[i+1])tmp--;
       //  printf("%d\n",tmp);
        if(val[i-1]){
            if(a[i-1]>a[i-2]&&a[i-1]>a[i+1]);
            else if(a[i-1]<a[i-2]&&a[i-1]<a[i+1]);
            else tmp--;
        }
        else if(i!=1){
            if(a[i-1]>a[i-2]&&a[i-1]>a[i+1])tmp++;
            else if(a[i-1]<a[i-2]&&a[i-1]<a[i+1])tmp++;
        }
        ans=min(ans,tmp);
    }
    printf("%d\n",ans);
  /*  int ans2=1e9;
    for(int i = 0;i<n;i++){
        int tmp[200005];
        for(int  j=0;j<n;j++){
            tmp[j]=a[j];
        }
        if(i!=0){
            tmp[i]=a[i-1];
            int sum=0;
            
        }
        if(i!=n-1){
            tmp[i]=a[i+1];
        }
    }*/
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/