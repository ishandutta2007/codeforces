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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 30005
#define next Next
#define index Index
int main(){
    char c[1005];
    scanf("%s",c);
    LL ans=0;
    int sum=0;
    int cnt=0;
    int dot=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]<='9'&&c[i]>='0'){
            sum=sum*10+c[i]-'0';
            if(dot)
            cnt++;
        }
        else if(c[i]=='.'){
            dot=1;
            cnt=0;
        }
        else{
            if(!dot||cnt!=2){
                sum*=100;
            }
          //  printf("%d\n",sum);
            ans+=sum;
            sum=0;
            dot=0;
            cnt=0;
  //          v.pb(sum);
        }
    }
    if(!dot||cnt!=2){
        sum*=100;
    }
    //printf("%d\n",sum);
    ans+=sum;
   // printf("%d\n",ans);
    LL tmp=ans;
    vector<char> res;
    int tot=0;
    while(ans){
        tot++;
        res.pb(ans%10+'0');
        if(tot%3==2)
            res.pb('.');
        ans/=10;

    }
    while(tot<3){
        res.pb('0');
        tot++;
        if(tot%3==2)
            res.pb('.');
    }
    if(res.back()=='.')res.pop_back();
    reverse(res.begin(),res.end());
    if(tmp%100==0)
    for(int t=0;t<3;t++)
        res.pop_back();
    for(auto it:res)
    printf("%c",it);
    printf("\n");
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */