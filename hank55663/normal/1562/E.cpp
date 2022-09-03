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
pll Hash[5005][5005];
int ans[5005][5005];
LL mod[2];
int n;
char c[5005];
int lcp[5005];
bool cmp(const int &a,const int &b){
    int Min=-1,Max=min(n-a,n-b)+1;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        if(Hash[a][a+mid]==Hash[b][b+mid])Min=mid;
        else Max=mid;
    }
    return c[a+Max]<c[b+Max];
}
void solve(){
    srand(time(NULL));
    for(int i = 0;i<2;i++){
        mod[i]=rand()%1000000000+1000000000;
        while(true){
            int ok=1;
            for(int j=2;j*j<=mod[i];j++){
                if(mod[i]%j==0){
                    ok=0;
                    break;
                }
            }
            if(ok)break;
            mod[i]++;
        }
    }

    scanf("%d",&n);
    scanf("%s",c+1);
    for(int j = 1;c[j]!=0;j++){
        for(int k = j;c[k]!=0;k++){
            pll p=Hash[j][k-1];
            p.x=p.x*26%mod[0];
            p.y=p.y*26%mod[1];
            p.x+=c[k]-'a';
            p.y+=c[k]-'a';
            p.x%=mod[0];
            p.y%=mod[0];
            Hash[j][k]=p;
        }
    }
    vector<int> v;
    int val[5005];
    MEM(val);
    for(int i = 1;i<=n;i++)v.pb(i);
    sort(v.begin(),v.end(),cmp);
  //  for(auto it:v)printf("%d ",it);
  //  printf("\n");
    lcp[0]=1e9;
    for(int i = 1;i<v.size();i++){
        lcp[i]=0;
        while(c[v[i]+lcp[i]]==c[v[i-1]+lcp[i]])lcp[i]++;
   //     printf(" %d",lcp[i]);
    }
   // printf("\n");
    int res=0;
    for(int i = 1;i<=n;i++){
        int last=0;
        int lastv=0;
        int Max=0;
        int ok=1;
        for(int j = i;j<=n;j++){
            while(lastv!=v.size()&&(v[lastv]+j-i>n||c[v[lastv]+j-i]<c[j])&&ok){
                Max=max(Max,val[lastv]);
                lastv++;
                if(lastv==v.size()||lcp[lastv]<j-i)ok=0;
            }
          //  printf("%d %d %d\n",lastv!=v.size(),(v[lastv]+j-i>n||c[v[lastv]+j-i]<c[j]),lcp[lastv]>=j-i&&ok);
            if(lastv!=v.size()&&c[v[lastv]+j-i]==c[j]);
            else ok=0;
            ans[i][j]=max(last,Max)+1;
            last=ans[i][j];
            res=max(res,last);
           // printf("%d ",last);
           // printf("%d %d\n%d %d %d\n",i,j,last,lastv,ok);
        }
        for(int j = 0;j<v.size();j++){
            if(v[j]==i)val[j]=last;
        }
       //printf("\n");
    }
    printf("%d\n",res);
}
int main(){
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

110111
*/