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
int a[100005];
int p;
int n,k;
int query(int x){
   printf("? %d\n",x+1);
   fflush(stdout);
   int res;
    scanf("%d",&res);
    return res;
   /* int res=a[x];
    int a2[100005];
    fill(a2,a2+100005,0);
    for(int i = 0;i<n;i++){
        if(i==p)a2[(i+1)%n]+=a[i];
        else a2[(i+1)%n]+=(a[i]+1)/2,a2[(i+n-1)%n]+=a[i]/2;
    }
    for(int i = 0;i<n;i++)a[i]=a2[i];*/
    return res;
}
bool solve(){
   // srand(time(NULL));
  //  int n,k;
   // scanf("%d %d",&n,&k);
    //k=rand()%100*2+10;
    //n=rand()%1000+4;
    //
    scanf("%d %d",&n,&k);
 //   for(int i = 0;i<n;i++){
    //    a[i]=k;
   // }
  //  p=rand()%n;
   // printf("%d %d %d\n",n,k,p);
    //
    int st=0;
    int val;
    int step=300;
    while(__gcd(step,n)!=1)step++;
    while(true){
     //   printf("? %d\n",st+1);
        fflush(stdout);
        //
        val=query(st);
        //scanf("%d",&val);
        if(val!=k)break;
        st=(st+step)%n;
    }
    if(val>k){
        int step=1;
        while(true){
        //    printf("? %d\n",(st-step+n)%n+1);
            fflush(stdout);
            int val2;
            //scanf("%d",&val2);
            val2=query((st-step+n)%n);
            if(val2<k){
                st=(st-step/2+n)%n;
                step=1;
            }
            else if(val2==k){
                printf("! %d\n",(st-step+n)%n+1);
               // assert(p==(st-step+n)%n);
                fflush(stdout);
                return true;
            }
            else{
                step<<=1;
            }
        }
    }
    else if(val<k){
        int step=1;
        while(true){
          //  printf("? %d\n",(st+step)%n+1);
            fflush(stdout);
            int val2;
            //scanf("%d",&val2);
            val2=query((st+step)%n);
            if(val2>k){
                st=(st+step/2)%n;
                step=1;
            }
            else if(val2==k){
                printf("! %d\n",(st+step)%n+1);
               // assert(p==(st+step)%n);
                fflush(stdout);
                return true;
            }
            else{
                step<<=1;
            }
        }
    }
    else{
        assert(0);
    }
    /*
    int p=0;
    for(int t=0;t<100;t++){
        for(int i = 0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        int a2[100005];
        fill(a2,a2+100005,0);
        for(int i = 0;i<n;i++){
            if(i==p)a2[(i+1)%n]+=a[i];
            else a2[(i+1)%n]+=(a[i]+1)/2,a2[(i+n-1)%n]+=a[i]/2;
        }
        for(int i = 0;i<n;i++)a[i]=a2[i];
    }*/
    return true;
}
int main(){

    int t=1;//00000;
   // scanf("%d",&t);
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