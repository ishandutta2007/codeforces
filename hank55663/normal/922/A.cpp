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
    int x,y;
    scanf("%d %d",&x,&y);
    int tot = x-y+1;
    if(x==0&&y==1){
        printf("Yes\n");
    }
    else if(y==1||y==0){
        printf("No\n");
    }
    else if(tot>=0&&tot%2==0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}