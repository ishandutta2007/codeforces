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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 200005
int main(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    if(n&1){
        printf("No\n");
    }
    else{
        int cnt=0,remain=0;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='(')cnt++;
            else cnt--;
            if(cnt<0){
                remain++;
                cnt++;
            }
        }
        if(cnt-remain==0&&remain<=1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}