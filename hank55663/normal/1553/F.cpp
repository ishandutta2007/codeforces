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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL S[300005],cnt[300005];;
void add(int x,int k,LL *s){
    x++;
    for(int i = x;i<300005;i+=i&-i){
        s[i]+=k;
    }
}
LL query(int x,LL *s){
    x++;
    LL res=0;
    if(x>=300005)x=300004;
    for(int i = x;i>0;i-=i&-i){
        res+=s[i];
    }
    return res;
}
LL S2[300005],cnt2[300005];
void solve(){
    int n;
    scanf("%d",&n);
    int p[200005];
    for(int i = 0;i<n;i++){
       // p[i]=100000+i;
        scanf("%d",&p[i]);
    }
    LL res=0;
    for(int i = 0;i<n;i++){
        for(int j  =0;j*p[i]<300005;j++){
            res+=query(p[i]*(j+1)-1,S)-query(p[i]*j-1,S)
                 -j*p[i]*(query(p[i]*(j+1)-1,cnt)-query(p[i]*j-1,cnt));
        }
        // printf("%lld\n",res);
        res+=(query(300000,cnt)-query(max(p[i],500),cnt))*p[i];
        
        for(int j = 1;j<=p[i];){
            int r=p[i]/j,l=p[i]/(j+1);
            l=max(l,500);
          //  printf("%d %d\n",l,r);
            if(l>=r)break;
            if(l+1==r){
                LL tcnt=0,tS=0;
                for(int k =l+1;k<=r;k++)tcnt+=cnt2[k],tS+=S2[k];
                res+=p[i]*tcnt-tS*j;
            }
            else{
                LL SS=0,cntt=0;
                for(int k  = r+1;k>0;k-=k&-k){
                    cntt+=cnt[k];
                    SS+=S[k];
                }
                for(int k = l+1;k>0;k-=k&-k){
                    cntt-=cnt[k];
                    SS-=S[k];
                }
                res+=p[i]*cntt-SS*j;
            }
          //  printf("%d %d\n",j,res);
            if(j==p[i])break;
            if(l==500)break;
            j=p[i]/l;
            
        }
       // printf("%lld\n",res);
        for(int j = 1;j<=500;j++){
            if(cnt2[j]){
                res+=p[i]%j;
            }
        }
        add(p[i],1,cnt);
        add(p[i],p[i],S);
        S2[p[i]]+=p[i];
        cnt2[p[i]]++;
        printf("%lld ",res);
    }
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/