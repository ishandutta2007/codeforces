#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
int main(){
    int x;
    scanf("%d",&x);
    while(x){
        int temp=x;
        int sum=0;
        while(temp){
            sum+=temp%10;
            temp/=10;
        }
        if(sum%4==0)break;
        x++;
    }
    printf("%d\n",x);
}
/*
1 
2 6 
3 5 
4
*/