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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int cnt[3000005];
LL ans[3000005];
int main(){
    int n;
    scanf("%d",&n);
    int a[1000005];
    vector<LL> v;
    for(int i = 0;i<n;i++){
      //a[i]=rand()%3000000+1;
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        v.pb((LL)a[i]*a[i]);
    }
    for(int i = 3000000;i>=0;i--)
        cnt[i]+=cnt[i+1];
    sort(v.begin(),v.end());
    for(int i = 1;i<=3000000;i++){
        LL num=cnt[i]-cnt[i+1];
        for(int j=1;j<=3000000;j++){
            if(i*j>3000000){
                ans[3000000]+=num*cnt[j];
                break;
            }
            else{
                ans[i*j]+=num*(cnt[j]-cnt[j+1]);
            }
        }
    }
    for(int i = 3000000;i>=0;i--){
        ans[i]+=ans[i+1];
    }
    int q;
    scanf("%d",&q);
  //  int ccnt=0;
    while(q--){
        int p;
        scanf("%d",&p);
        LL res=ans[p];

        res-=v.end()-lower_bound(v.begin(),v.end(),p);
        printf("%lld\n",res);
        assert(res%2==0);
      //  printf("%lld\n",ans/2);
    }
//    printf("%d\n",ccnt);
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/