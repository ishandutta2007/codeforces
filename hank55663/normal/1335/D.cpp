#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a[9][9];
        for(int i = 0;i<9;i++){
            for(int j=0;j<9;j++){
                char c;
                scanf(" %c",&c);
                a[i][j]=c-'0';
            }
        }
        vector<int> v;
        for(int i=  0;i<3;i++){
            v.pb(a[i*3][0+i]);
            v.pb(a[i*3+1][3+i]);
            v.pb(a[i*3+2][6+i]);
        }
      //  for(auto it:v)printf("%d ",it);
      //  printf("\n");
     //   rotate(v.begin(),v.begin()+1,v.end());
        //for(auto it:v)printf("%d ",it);
        //printf("\n");
        int now=0;
        for(int i=  0;i<3;i++){
            for(int j=0;j<9;j+=3){
                a[i*3+j/3][j+i]=v[now++]%9+1;
            }
        }
        for(int i = 0;i<9;i++){
            for(int j=0;j<9;j++){
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
    }

}
/*
00 00
01 10
10 11
11 01
2 1 3 0 2
3 1 3 0 2
3 2 3 0 2
3 2 4 0 2
3 2 4 1 2
3 2 4 1 3
*/