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
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int p[100005];
    int belong[256];
    int size[256];
    MEMS(belong);
    belong[0]=0;
    for(int i=0;i<256;i++)
    size[i]=1;
    for(int i=0;i<n;i++)
    scanf("%d",&p[i]);
    for(int i=0;i<n;i++){
        if(belong[p[i]]!=-1)
        printf("%d ",belong[p[i]]);
        else{
            int ans=1e9;
            for(int j=p[i];j>p[i]-k&&j>=0;j--){
                if(belong[j]==-1)
                ans=j;
                else if(belong[j]>p[i]-k)
                ans=belong[j];
            }
            for(int j=p[i];j>=ans;j--)
            belong[j]=ans;
            printf("%d ",belong[p[i]]);
        }
    }
}
/*
6 4 8 2
4 8 2 2
6 8 2 2
6 4 2 2
6 2 2
6 4 2
8 2 2

*/