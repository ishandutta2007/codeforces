#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define hash Hash
LL mod;
LL base[1000005];
LL hash[1000005];
LL xx=1e9;
LL f_pro(LL a,LL b){
    LL res=0,temp=a;
    while(b){
        res=(res+temp*(b&127))%mod;
        temp=temp*128%mod;
        b>>=7;
    }
    return res;
}
LL value(int l,int r){
    return ((hash[r]-f_pro(hash[l-1],base[r-l+1]))%mod+mod)%mod;
}
char c[1000005];
int n;
void print(int x,int y){
    for(int j = 1;j<=n;j++){
        printf("%c",c[j]);
        if(j==x)
        printf("+");
        if(j==y)
        printf("=");
    }
    printf("\n");
}
int main(){
    srand(time(NULL));
    mod=rand()+1;
    mod<<=20;
    mod%=xx;
    mod+=rand();
    mod%=xx;
    mod<<=21;
    mod+=rand();

    scanf("%s",c+1);
    hash[0]=0;
    base[0]=1;
    for(int i = 1;c[i]!=0;i++){
        hash[i]=(hash[i-1]*10+c[i]-'0')%mod;
        base[i]=base[i-1]*10%mod;
    }
    n=strlen(c+1);
    for(int i = 1;i<=n;i++){
        if(i+1>n-i)
        break;
        LL x=value(1,i);
        LL y=value(i+1,n-i);
        LL z=value(n-i+1,n);
        //printf("%d %d %d %d\n",i,x,y,z);
        if((c[1]!='0'||i==1)&&(c[i+1]!='0'||n-i==i+1)&&(c[n-i+1]!='0'||n-i+1==n)){
            if((x+y)%mod==z){
            print(i,n-i);
            return 0;
            }
        }
        if(i+1>n-i-1)
        continue;
        y=value(i+1,n-i-1);
        z=value(n-i,n);
        //printf("%d %d %d %d\n",i,x,y,z);
        if((c[1]!='0'||i==1)&&(c[i+1]!='0'||n-i-1==i+1)&&(c[n-i]!='0'||n-i==n)){
            if((x+y)%mod==z){
                print(i,n-i-1);
                return 0;
            }
        }
    }
    for(int j=n;j>=0;j--){
        LL x,y,z;
        z=value(j,n);
        if(j-(n-j+1)-1>=1){
        //break;
            x=value(1,j-(n-j+1)-1);
            y=value(j-(n-j+1),j-1);

           // printf("%d %d %d %d\n",j,x,y,z);
            if((c[1]!='0'||j-(n-j+1)-1==1)&&(c[j-(n-j+1)]!='0'||j-1==j-(n-j+1))&&(c[j]!='0'||j==n))
            if((x+y)%mod==z){
                print(j-(n-j+1)-1,j-1);
                return 0;
            }
        }
        if(n-j+1==1)
        continue;
        if(j-(n-j+1)>=1){
            x=value(1,j-(n-j+1));
            y=value(j-(n-j+1)+1,j-1);
           // printf("%d %d %d %d\n",j,x,y,z);
            if((c[1]!='0'||j-(n-j+1)==1)&&(c[j-(n-j+1)+1]!='0'||j-1==j-(n-j+1)+1)&&(c[j]!='0'||j==n))
            if((x+y)%mod==z){
                print(j-(n-j+1),j-1);
                return 0;
            }
        }
    }
}
/*
1 8 18
2 7 17
3 6 16
4 5 15
5 14
6 13
7 12
8 11
9 10
10 19
11 18
12 17
13 16
14 15
0 ~ 2345 2
2346 ~ 9999 1
 9999
12345
*/