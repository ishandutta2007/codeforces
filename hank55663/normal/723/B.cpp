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
#define MXN 30005
#define next Next
#define index Index
int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    int sum=0;
    int ans1=0,ans2=0;
    char c[1005];
    scanf("%s",c);
    c[n]='_';c[n+1]=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]>='A'&&c[i]<='Z'){
            sum++;
        }
        else if(c[i]>='a'&&c[i]<='z'){
            sum++;
        }
        else{
        //    printf("%d %d\n",cnt,sum);
            if(sum){
                if(cnt){
                    ans2++;
                }
                else{
                    ans1=max(ans1,sum);
                }
                sum=0;
            }
        }
        if(c[i]=='(')cnt++;
        else if(c[i]==')')cnt--;
    }
    printf("%d %d\n",ans1,ans2);
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */