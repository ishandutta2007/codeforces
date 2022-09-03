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
    char c[105];
    scanf("%s",c);
    int ok=0,cnt=0;
    for(int i =0;c[i]!=0;i++){
        if(c[i]=='1'){
            ok=1;
        }
        if(c[i]=='0'&&ok){
            cnt++;
        }
    }
    if(cnt>=6){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/