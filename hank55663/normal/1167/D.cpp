#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    int cnt=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='('){
            cnt++;
            if(cnt&1){
                printf("0");
            }
            else{
                printf("1");
            }
        }
        else{
            if(cnt&1){
                printf("0");
            }
            else{
                printf("1");
            }
            cnt--;
        }
    }
    printf("\n");
}