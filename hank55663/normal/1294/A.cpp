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
#define ld long double
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,n;
        scanf("%d %d %d %d",&a,&b,&c,&n);
        int tot=a+b+c+n;
        if(tot%3!=0||tot/3<a||tot/3<b||tot/3<c){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
}