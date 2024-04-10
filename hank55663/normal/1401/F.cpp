#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
LL S[1000005];
LL a[1000005];
void add(int x,LL k){
    x++;
    for(int i =x;i<1000005;i+=i&-i){
        S[i]+=k;
    }
}
LL query(int x){
    x++;
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
LL ask(int l,int r){
   // printf("%d %d\n",l,r);
    return query(r)-query(l-1);
}
LL query(int x,int mask,int n){
    if(x==-1)return 0;
    LL res=0;
    LL now=0;
    for(int i = n-1;i>=0;i--){
        if(x&(1<<i)){
            if(mask&(1<<i)){
                res+=ask(now+(1<<i),now+(1<<i)+(1<<i)-1);
            }
            else{
                res+=ask(now,now+(1<<i)-1);
                now+=(1<<i);
            }
        }
        else{
            if(mask&(1<<i)){
                now+=(1<<i);
            }
        }
    }
    res+=ask(x^mask,x^mask);
    //printf("?%d %d\n",x,res);
    return res;
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 0;i<(1<<n);i++){
        scanf("%lld",&a[i]);
        add(i,a[i]);
    }
    int now=0;
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,k;
            scanf("%d %d",&x,&k);
            x--;
            x^=now;
            add(x,-a[x]);
            add(x,k);
            a[x]=k;
        }
        if(op==2){
            int k;
            scanf("%d",&k);
            for(int i = 0;i<k;i++)now^=(1<<i);
        }
        if(op==3){
            int k;
            scanf("%d",&k);
            now^=(1<<k);
        }
        if(op==4){
            int l,r;
            scanf("%d %d",&l,&r);
            r--;
            l--;
            printf("%lld\n",query(r,now,n)-query(l-1,now,n));
        }
    }
}
int main()
{
    int t=1;
    //scanf("%d",&t);
    int T=1;
    while(t--){
        solve();
    }
}