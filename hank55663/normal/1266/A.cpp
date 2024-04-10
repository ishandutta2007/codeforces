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
    int t;
    scanf("%d",&t);
    while(t--){
        char c[1005];
        scanf("%s",c);
        int zero=0,even=0,sum=0;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='0')zero++;
            if((c[i]-'0')%2==0)even++;
            sum+=c[i]-'0';
        }
        if(sum%3==0&&zero&&even>=2){
            printf("red\n");
        }
        else{
            printf("cyan\n");
        }
    }
}
/*
510510

255255
170170
102102
72930
46410
39270
30030

5 3
3 -1 
4 2 
1 1 
5 3 
2 2 
4 1 
3 2 
5 3 

*/