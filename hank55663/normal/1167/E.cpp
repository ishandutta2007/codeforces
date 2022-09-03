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
int Max[1000005],Min[1000005],rMin[1000005];
int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    int a[1000005];
    //fill(Max,Max+x+1,1e9);
    fill(rMin,rMin+x+1,1e9);
    set<int> s;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        s.insert(a[i]);
        if(*s.rbegin() != a[i])
        Max[a[i]]=*s.rbegin();
        if(s.upper_bound(a[i])!=s.end()){
            int x=*s.upper_bound(a[i]);
            Min[x]=max(Min[x],a[i]);
            rMin[a[i]]=min(rMin[a[i]],x);
        }
    }
    int Maxlen=2;
    for(int i = x;i>=Maxlen;i--){
        Maxlen=max(Maxlen,Min[i]+1);
    }
    int Maxlen2=x;
    LL ans=x-Maxlen+2;
//   printf("%lld\n",ans);
    for(int i = 1;i<=Maxlen2;i++){
        Maxlen2=min(rMin[i]-1,Maxlen2);
        Maxlen=max(max(Max[i]+1,Maxlen),i+2);
        ans+=x-Maxlen+2;
      //  printf("%d %d %d \n",x-Maxlen+2,Maxlen,Maxlen2);
    }
    printf("%lld\n",ans);
}