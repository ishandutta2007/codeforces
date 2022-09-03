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
int main(){
    int s,x1,x2;
    scanf("%d %d %d",&s,&x1,&x2);
    int t1,t2;
    scanf("%d %d",&t1,&t2);
    int p,d;
    scanf("%d %d",&p,&d);
    int ans;
    if(x1<x2){
        int dis=x2-x1;
        ans=dis*t2;
    }
    else{
        int dis=x1-x2;
        ans=dis*t2;
    }
    if(t1<t2){
        int cnt=0;
        while(p!=x1){
            cnt++;
            p+=d;
            if(p<0){
                d=-d;
                p+=2;
            }
            if(p>s){
                d=-d;
                p-=2;
            }
        }
        while(p!=x2){
            cnt++;
            p+=d;
            if(p<0){
                d=-d;
                p+=2;
            }
            if(p>s){
                d=-d;
                p-=2;
            }
        }
        ans=min(ans,cnt*t1);
    }
    printf("%d\n",ans);
}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */