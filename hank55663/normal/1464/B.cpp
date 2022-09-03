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
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
char c[100005];
string ss;
LL ans;
void dfs(int i,int x,int y){
    if(c[i]==0){
        LL zero=0,one=0;
        LL sum=0;
        for(int j=0;c[j]!=0;j++){
            if(c[j]=='0'){
                sum+=one*y;
                zero++;
            }
            else{
                sum+=zero*x;
                one++;
            }
        }
        if(sum<ans){
            ans=min(ans,sum);
            ss=string(c);
        }
        return;
    }
    if(c[i]=='?'){
        c[i]='1';
        dfs(i+1,x,y);
        c[i]='0';
        dfs(i+1,x,y);
        c[i]='?';
    }
    else{
        dfs(i+1,x,y);
    }
}
bool solve(){
    ans=1e18;
    scanf("%s",c);
    /*for(int i = 0;i<20;i++){
        c[i]="01?"[rand()%3];
    }*/
    int x=rand()%100+1,y=rand()%100+1;
    scanf("%d %d",&x,&y);
   // LL ans2=1e18;
    LL zero=0,one=0;
    LL sum1=0;
    for(int i=0;c[i]!=0;i++){
        if(c[i]=='1'){
            sum1+=zero*x;
            one++;
        }   
        else{
            sum1+=one*y;
            zero++;
        }
    }
    LL ans2=sum1;
    LL zero2=0,one2=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='0'){
            zero2++;
            zero--;
        }
        else if(c[i]=='1'){
            one2++;
            one--;
        }
        else{
            zero--;
            sum1=sum1-one2*y-one*x;
            sum1=sum1+zero2*x+zero*y;
            one2++;
        }
        ans2=min(ans2,sum1);
    }
    one=one2;
    zero=zero2;
    zero2=0,one2=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='0'){
            zero2++;
            zero--;
        }
        else if(c[i]=='1'){
            one2++;
            one--;
        }
        else{
            one--;
            sum1=sum1-zero2*x-zero*y;
            sum1=sum1+one2*y+one*x;
            zero2++;
        }
        ans2=min(ans2,sum1);
    }
    /*zero=0;
    one=0;
    LL sum2=0;
     for(int i=0;c[i]!=0;i++){
        if(c[i]=='0'){
            sum2+=one*y;
            zero++;
        }   
        else{
            sum2+=zero*x;
            one++;
        }
    }*/
   // dfs(0,x,y);
    //cout<<ss<<endl;
    printf("%lld\n",ans2);
    //assert(ans2==ans);
    return true;
}
int main(){
    int t=1;//000000;//000000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/