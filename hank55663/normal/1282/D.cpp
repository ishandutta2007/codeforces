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
#define rank Rank
#define KK 500
#define N 100005
int main(){
    int dis1,dis2;
    printf("a\n");
    fflush(stdout);
    scanf("%d",&dis1);
    if(dis1==300){
        for(int j=0;j<300;j++){
            printf("b");
        }
        printf("\n");
        fflush(stdout);
        return 0;
    }
    if(dis1==0)return 0;
    string s;
    for(int i = 0;i<=dis1;i++){
        s+="a";
    }
    printf("%s\n",s.c_str());
    fflush(stdout);
    int x;
    scanf("%d",&x);
    if(x==0)return 0;
    if(x==dis1+1){
        for(int i = 0;i<dis1;i++){
            printf("b");
        }
        printf("\n");
        fflush(stdout);
        int x;
        scanf("%d",&x);
        assert(x==0);
        return 0;
    }
    for(int i = 0;i<=dis1;i++){
        s[i]='b';
        printf("%s\n",s.c_str());
        fflush(stdout);
        int y;
        scanf("%d",&y);
        if(y==x-1){
            x=y;
        }
        else{
            s[i]='a';
        }
        if(y==0)return 0;
    }
}