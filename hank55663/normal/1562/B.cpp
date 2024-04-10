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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 3000000
int isprime[1005];
void solve(){
    int n;
    scanf("%d",&n);
    char c[55];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        if(!isprime[c[i]-'0']){
            printf("1\n%c\n",c[i]);
            return ;
        }
    }
      for(int i = 0;c[i]!=0;i++){
          for(int j = i+1;c[j]!=0;j++){
            if(!isprime[(c[i]-'0')*10+c[j]-'0']){
                printf("2\n%c%c\n",c[i],c[j]);
                return ;
            }
          }
    }
      for(int i = 0;c[i]!=0;i++){
          for(int j = i+1;c[j]!=0;j++){
            for(int k = j+1;c[k]!=0;k++){
                if(!isprime[(int)(c[i]-'0')*100+(int)(c[j]-'0')*10+c[k]-'0']){
                    printf("3\n%c%c%c\n",c[i],c[j],c[k]);
                    return ;//0;
                }
            }
        }
    }
}
int main(){
    fill(isprime,isprime+1005,1);
    isprime[1]=0;
    for(int i = 2;i<1005;i++){
        if(isprime[i])
        for(int j=i*2;j<1005;j+=i)isprime[j]=0;
    }
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
100
5 6
9 10 7 5
4 4 4 9
1 2
4 5
3 5
2 3
1 4
1 5

*/