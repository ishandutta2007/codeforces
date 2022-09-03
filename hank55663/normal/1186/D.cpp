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
#define MXN 10005
#define less Less
int main(){
    int n;
    scanf("%d",&n);
    pii p[100005];
    LL tot=0;
    for(int t = 0;t<n;t++){
        char c[15];
        scanf("%s",c);
        int num=0;
        int flag=1;
        if(c[0]=='-')  flag=-1;
        for(int i = 0;c[i]!=0;i++){
            if(c[i]=='.')
            break;
            if(c[i]>='0'&&c[i]<='9')
                num=num*10+c[i]-'0';
        }
        int ok=0;
        for(int i =strlen(c)-1;i>=strlen(c)-5;i--){
            if(c[i]!='0')
                ok=1;
        }
       // printf("%d %d %d\n",num,flag,ok);
        if(!ok){
            num*=flag;
            p[t]=mp(num,num);
            tot+=num;
        }
        else{
            if(flag==-1){
                num*=flag;
                p[t]=mp(num-1,num);
                tot+=num-1;
            }
            else{
                p[t]=mp(num,num+1);
                tot+=num;
            }
        }
    }
    for(int i = 0;i<n;i++){
       //printf("%d %d\n",p[i].x,p[i].y);
        if(p[i].x!=p[i].y&&tot<0){
            tot++;
            p[i].x=p[i].y;
        }
        printf("%d\n",p[i].x);
    }
}