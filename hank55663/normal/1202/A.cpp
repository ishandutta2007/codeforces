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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
//#define next Next
#define index Index
#define rank Rank
#define context Context
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[100005],c2[100005];
        scanf("%s %s",c,c2);
        int len1=strlen(c),len2=strlen(c2);
        reverse(c,c+len1);
        reverse(c2,c2+len2);
        int a=0,b;
        for(int i=0;c2[i]!=0;i++){
            if(c2[i]=='1'){
                b=i;
                break;
            }
        }
        for(int i=b;i<=len1;i++){
            if(c[i]=='1'){
                a=i;
                break;
            }
        }

        if(a<=b){
            printf("0\n");
        }
        else{
            printf("%d\n",a-b);
        }
    }
    return 0;
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */