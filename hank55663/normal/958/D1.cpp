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
    int m;
    scanf("%d",&m);
    pii num[200005];
    map<pii,int> mm;
    for(int i=0;i<m;i++){
        char c[20];
        scanf("%s",c);
        int a[10];
        int x=0;
        int now=0;
        for(int j=1;c[j]!=0;j++){
            if(c[j]<'0'||c[j]>'9'){
                a[now++]=x;
               // printf("%d ",x);
                x=0;
            }
            else{
                x*=10;
                x+=c[j]-'0';
            }
        }
        int gcd=__gcd(a[0]+a[1],x);
        num[i]=mp((a[0]+a[1])/gcd,x/gcd);
     //   printf("%d %d\n",num[i].x,num[i].y);
        mm[num[i]]++;
    }
    for(int i=0;i<m;i++){
        printf("%d ",mm[num[i]]);
    }
}