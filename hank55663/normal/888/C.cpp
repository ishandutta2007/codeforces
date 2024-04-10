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
int main(){
    char c[100005];
    scanf("%s",c+1);
    int ans=1e9;
    int last=0;
    int len=strlen(c+1);
    for(char i='a';i<='z';i++){
        int last=0;
        int Max=0;
        for(int j  =1;c[j]!=0;j++){
            if(c[j]==i){
                Max=max(Max,j-last);
                last=j;
            }
        }
        Max=max(Max,len+1-last);
        ans=min(Max,ans);
    }
    printf("%d\n",ans);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/