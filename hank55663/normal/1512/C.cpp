#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
static const double INF = 2147483647;
void solve(){
    int a,b;
    scanf("%d %d",&a,&b);
    char c[400005];
    scanf("%s",c);
    if(a%2==1&&b%2==1){
        printf("-1\n");
        return ;
    }
    if(a%2==1){
        if(c[(a+b)/2]=='1'){
            printf("-1\n");
            return;
        }
        c[(a+b)/2]='0';
    }
    if(b%2==1){
        if(c[(a+b)/2]=='0'){
            printf("-1\n");
            return;
        }
        c[(a+b)/2]='1';
    }
    int n=a+b;
    int l=0,r=a+b-1;
    int tot=0;
    a/=2;
    b/=2;
    while(l<r){
        if(c[l]!=c[r]){
            if(c[l]!='?'&&c[r]!='?'){
                printf("-1\n");
                return;
            }
            if(c[l]=='?')c[l]=c[r];
            else c[r]=c[l];
        }
        if(c[l]=='?')tot++;
        if(c[l]=='0')a--;
        if(c[l]=='1')b--;
        l++;
        r--;
    }
    if(a<0||b<0)printf("-1\n");
    else{
        int l=0,r=n-1;
        while(l<r){
            if(c[l]=='?'){
                if(a)c[l]=c[r]='0',a--;
                else c[l]=c[r]='1',b--;
            }
            l++;
            r--;
        }
        printf("%s\n",c);
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/