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
int main(){
    int n;
    scanf("%d",&n);
    char ans[15]="0000000000";
    char c[100005];
    scanf("%s",c);
    for(int i = 0;i<n;i++){
        if(c[i]=='L'){
            for(int j =0;j<10;j++){
                if(ans[j]=='0'){
                    ans[j]='1';
                    break;
                }
            }
        }
        else if(c[i]=='R'){
            for(int j = 9;j>=0;j--){
                if(ans[j]=='0'){
                    ans[j]='1';
                    break;
                }
            }
        }
        else{
            ans[c[i]-'0']='0';
        }
    }
    printf("%s\n",ans);
}