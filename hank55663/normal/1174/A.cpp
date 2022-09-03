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
#define MXN 3005
#define next Next
int main(){
   int n;
   scanf("%d",&n);
   n*=2;
   int a[2005];
   for(int i = 0;i<n;i++){
       scanf("%d",&a[i]);
   }
   sort(a,a+n);
   if(a[0]==a[n-1]){
       printf("-1\n");
   }
   else{
       for(int i = 0;i<n;i++)
        printf("%d ",a[i]);
   }
}
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/