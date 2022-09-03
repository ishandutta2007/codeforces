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
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
int Size=500;
vector<int> v;
int tot[102200005];
int main(){
    char c[200005];
    MEM(c);
    scanf("%s",c+1);
    v.pb(0);
   /* for(int i = 1;i<=200000;i++){
       c[i]='0';
       // if(rand()%10000==0)c[i]='1';
      //  else c[i]='0';
    }
    int x;
    scanf("%d",&x);
    c[x]='1';*/
    int cnt[200005];
    cnt[0]=0;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='1'){
            v.pb(i);
            cnt[i]=cnt[i-1]+1;
        }
        else{
            cnt[i]=cnt[i-1];
        }
    }
    LL ans=0;
    int n=strlen(c+1);
    v.pb(n+1);
    for(int i = 1;i<=Size;i++){
      //  printf("%d\n",i);
        //unordered_map<int,int> m;
        vector<int> v;
        for(int j=0;j<=n;j++){
            ans+=tot[cnt[j]*i-j+n];
            tot[cnt[j]*i-j+n]++;
            v.pb(cnt[j]*i-j+n);
        }
        for(auto it:v)
        tot[it]=0;
    }
  //  printf("%lld\n",ans);
    for(int i = 1;i<v.size()-1;i++){
        for(int j=i;j<=i+410&&j<v.size()-1;j++){
         //   printf("%d %d\n",i,j);
            int maxlen=v[j+1]-v[i-1]-1,minlen=v[j]-v[i]+1;
          /*  int mid=(maxlen+minlen)/2;
            //Size+1 mid/(j-i)
            if(Size+1<=mid/(j-i)){
                int l=Size+1,r=mid/(j-i+1);
                int vl=l*(j-i+1),vr=r*(j-i+1);
                LL val1=vl-minlen+1,val2=vr-minlen+1;
                ans+=(val1+val2)*(vr-vl+1)/2;
            }
            //mid/(j-i)+1 maxlen/(j-i)
            if(Size+1<=maxlen/(j-i)){
                int l=max(Size+1,mid/(j-i)+1),r=maxlen/(j-i);
                int vl=l*(j-i),vr=r*(j-i);
                LL val1=maxlen-vl+1,val2=maxlen-vr+1;
                ans+=(val1+val2)*(vr-vl+1)/2;
            }*/
            
            for(int k=max(Size+1,(minlen+j-i)/(j-i+1));(j-i+1)*k<=maxlen;k++){
                int need=k*(j-i+1);
                int num=min(min(maxlen-need+1,need-minlen+1),min(v[j+1]-v[j],v[i]-v[i-1]));
                ans+=max(num,0);
            }
        }
    }
    printf("%lld\n",ans);
}
/*
1-n 0
2-n 1
3-n 2
*/
/*

k*cnt[i]-k*cnt[j]=i-j;
k*cnt[i]-i=k*cnt[j]-j
1 2 3 4 5
1 2 3 4 5 6
1 2 3 4 5    3
1 2 3 5 6    4 
1 2 3 4 6
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/