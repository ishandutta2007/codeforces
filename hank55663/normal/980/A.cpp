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
    char c[1005];
    scanf("%s",c);
    int a=0,b=0;
    for(int i=0;c[i]!=0;i++){
        if(c[i]=='o')
        a++;
        else
        b++;
    }
    if(a==0||b%a==0)
    printf("YES\n");
    else
    printf("NO\n");
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