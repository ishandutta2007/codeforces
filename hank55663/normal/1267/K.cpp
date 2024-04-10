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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
  ///  int cnt[2000005];
  //  LL ans[2000005];
LL C[20][20];
void build(){
    for(int i = 0;i<20;i++){
        C[i][0]=C[i][i]=1;
        for(int j =1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
}
int main(){
    build();
    int t;
    scanf("%d",&t);
    while(t--){
        LL n=rand()%100000;
        //printf("%lld\n",n);
        scanf("%lld",&n);
        LL tmp=1;
        LL x=n;
        for(int i = 2;x;i++){
            x/=i;
            tmp*=i;
        }
        //LL ans=tmp;
        vector<int> v;
        for(int i=2;n;i++){
            v.pb(n%i);
            n/=i;
         //   if(n==0){
           //     printf("%lld\n",ans/i+1);
        //    }
        }

/*
        sort(v.begin(),v.end());
        int aans=0,aans2=0;
        do{
            int ok=1;
            for(int i = 0;i<v.size();i++){
                if(v[i]>i+1)ok=0;
             //   printf("%d ",v[i]);
            }
         //   printf("%d\n",ok);
           // if(v.back()==0)ok=0;
            aans+=ok;
            if(ok&&v.back()==0)aans2++;
        }while(next_permutation(v.begin(),v.end()));
        int ans3=0;
        for(int i =1;i<=10000000;i++){
            vector<int> tmp;
            int x=i;
            for(int j=2;x;j++){
                tmp.pb(x%j);
                x/=j;
            }
            sort(tmp.begin(),tmp.end());
            if(tmp.size()>v.size())break;
            if(tmp==v)ans3++;
        }*/
        sort(v.begin(),v.end());
        LL ans=1;
        int tot=v.size();
        reverse(v.begin(),v.end());
        int cnt=1;
     //   for(auto it:v)
      //  printf("%d ",it);
      //  printf("\n");
        for(int i=1;i<v.size();i++){
            if(v[i]!=v[i-1]){
                ans*=C[tot-i+cnt-max(v[i-1]-1,0)][cnt];
            //    printf("%d %d\n",tot-i+cnt-max(v[i-1]-1,0),cnt);
                cnt=1;
            }
            else    cnt++;
            //ans*=(tot-i-max(v[i]-1,0));
         //   printf("%d\n",(tot-i-max(v[i]-1,0)));
        }
        
  //      printf("%lld\n",ans);
        LL ans2=1;
        if(v.back()!=0)ans2=0;
        else{
            v.pop_back();
            if(v.back()>1)ans2=0;
            tot=v.size();
        // printf("%d\n",tot);
            int cnt=1;
            for(int i=1;i<v.size();i++){
                if(v[i]!=v[i-1]){
                    ans2*=C[tot-i+cnt-max(v[i-1]-1,0)][cnt];
                    cnt=1;
                }
                else    cnt++;
                //ans*=(tot-i-max(v[i]-1,0));
            //   printf("%d\n",(tot-i-max(v[i]-1,0)));
            }
            //for(int i=0;i<v.size();i++)
             //   ans2*=(tot-i-max(v[i]-1,0));
            if(v.empty())ans2=0;
        }
      //  printf("%lld\n",ans2);
     // printf("%lld %lld\n",ans,ans2);
        printf("%lld\n",ans-ans2-1);// %lld %lld %d %lld\n",ans,ans2-1,aans,aans2-1,ans3-1);
        //assert(ans-ans2-1==aans-aans2-1&&ans3-1==ans-ans2-1);
    }
}
/*
2 -2000000000 2 -20000000000 1 1
*/