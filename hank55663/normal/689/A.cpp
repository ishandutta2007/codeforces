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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int main(){
    int n;
    scanf("%d",&n);
    char c[15];
    scanf("%s",c);
    int u=0,d=0,l=0,r=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='1'||c[i]=='4'||c[i]=='7'||c[i]=='0')l=1;
        if(c[i]=='3'||c[i]=='6'||c[i]=='9'||c[i]=='0')r=1;
        if(c[i]>='1'&&c[i]<='3')u=1;
        if(c[i]=='7'||c[i]=='9'||c[i]=='0')d=1;
    }
    if(u&&d&&l&&r){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/