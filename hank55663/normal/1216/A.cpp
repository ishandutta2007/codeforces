#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int main(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    int cnt=0;
    for(int i=0;c[i]!=0;i+=2){
        if(c[i]==c[i+1]){
            c[i]=(int)'a'+'b'-c[i];
            cnt++;
        }
    }
    printf("%d\n%s\n",cnt,c);
}