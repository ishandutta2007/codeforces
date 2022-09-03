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
    char c[1000005];
    scanf("%s",c);
    char b[1000005];
    scanf("%s",b);
    int len=strlen(b);
    int cnt=0;
    for(int i = 0;b[i]!=0;i++){
        if(b[i]=='1')
            cnt++;
    }
    for(int i = 0;i<len-1;i++){
        if(c[i]=='1')
            cnt--;
    }
    int ans=0;
    for(int i =len-1;c[i]!=0;i++){
        if(c[i]=='1')
            cnt--;
        if(cnt%2==0)
        ans++;
        if(c[i-len+1]=='1')
            cnt++;
    }
    printf("%d\n",ans);
}