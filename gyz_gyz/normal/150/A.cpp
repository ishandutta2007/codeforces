#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define ll long long
using namespace std;
ll n,ii,s,ans;
int main(){
    scanf("%I64d",&n);ans=1;
    rep(i,2,n){ii=i;
        if(ii*ii>n)break;
        while(n%ii==0){
            n/=ii;s++;
            if(s<=2)ans*=ii;
        }
    }
    if(n>1){s++;if(ans<=2)ans*=n;n=1;}
    if(s<=1)printf("1\n0\n");
    if(s==2)printf("2\n");
    if(s>2)printf("1\n%I64d\n",ans);
}