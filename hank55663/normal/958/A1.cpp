#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main() {
   int n;
   scanf("%d",&n);
   char c[15][15];
   for(int i=0;i<n;i++){
       scanf("%s",c[i]);
   }
   char c1[15][15];
   for(int i=0;i<n;i++)
    scanf("%s",c1[i]);
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            int ok=1;
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++){
                    if(c[j][k]!=c1[j][k])
                        ok=0;
                }
            if(ok){
                printf("Yes\n");
                return 0;
            }
            char temp[15][15];
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    temp[j][k]=c1[j][k];
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    c1[j][k]=temp[n-1-k][j];
        }
        for(int j=0;j<n;j++){
            reverse(c1[j],c1[j]+n);
        }
    }
    printf("No\n");
}