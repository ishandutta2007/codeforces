#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int n;
bool cmp(LL *a,LL *b){
    for(int i = 0;i<n;i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
bool check(LL *b){
    for(int i= 1;i<n;i++){
        if(b[i]<=b[i-1])return false;
    }
    return true;
}
int main(){
    //int n;
    scanf("%d",&n);

    LL a[200005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    LL b[200005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&b[i]);
    }
    if(n==1){
        if(a[0]==b[0])printf("SMALL\n0\n\n");
        else{
            printf("IMPOSSIBLE\n");
        }
        return 0;
    }
    if(n==2){
        LL tot=0;
        LL sum=0;
        vector<pll> v;
        while(true){
        //    printf("%lld %lld\n",b[0],b[1]);
         //   getchar();
           // if(tot>200000)v.clear();
            if(b[0]==0){
                printf("IMPOSSIBLE\n");
                return 0;
            }
            if(b[0]==a[0]&&b[1]==a[1]){
                break;
            }
            if(b[0]==a[1]&&b[1]==a[0]){
                v.pb(mp(1,1));
                
                sum++;
                break;
            //    return 0;
            }
            if(b[0]>b[1]){
                v.pb(mp(1,1));
                swap(b[0],b[1]);
                sum++;
                continue;
            }
            if(b[0]==a[0]){
                if((b[1]-a[1]>=0)&&(b[1]-a[1])%b[0]==0){
                    v.pb(mp(0,(b[1]-a[1])/b[0]));
                    tot+=(b[1]-a[1])/b[0];
                    sum+=(b[1]-a[1])/b[0];
                    break;
                }
                else{
                    v.pb(mp(0,(b[1])/b[0]));
                    tot+=(b[1])/b[0];
                    sum+=b[1]/b[0];
                    b[1]%=b[0];
                    continue;
                }
            }
            if(b[0]==a[1]){
                if((b[1]-a[0])>=0&&(b[1]-a[0])%b[0]==0){
                    v.pb(mp(0,(b[1]-a[0])/b[0]));
                    tot+=(b[1]-a[0])/b[0];
                    sum+=(b[1]-a[0])/b[0];
                    v.pb(mp(1,1));
                    sum++;
                    break;
                }
                else{
                    v.pb(mp(0,(b[1])/b[0]));
                    tot+=(b[1])/b[0];
                    sum+=b[1]/b[0];
                    b[1]%=b[0];
                    continue;
                }
            }
            v.pb(mp(0,(b[1])/b[0]));
            tot+=(b[1])/b[0];
            sum+=b[1]/b[0];
            b[1]%=b[0];
        }
        if(tot>200000){
            printf("BIG\n%lld\n",tot);
        }
        else{
            printf("SMALL\n%lld\n",sum);
            reverse(v.begin(),v.end());
            for(auto it:v){
                for(int i=0;i<it.y;i++){
                    printf("%c","PR"[it.x]);
                }
               
            }
             printf("\n");
        }
    }
    else{
        int tot=0;
        vector<int> v;
        while(!cmp(a,b)){
            if(!check(b)){
                reverse(b,b+n);
                if(v.size()&&v.back()==1){
                    printf("IMPOSSIBLE\n");
                    return 0;
                }
                v.pb(1);
            }
            else{
                v.pb(0);
                tot++;
                for(int i=n-1;i>=1;i--)b[i]-=b[i-1];
            }
         //   if(tot>200000)v.clear();
        }
        if(tot>200000){
            printf("BIG\n");
            printf("%d\n",tot);
        }
        else{
            printf("SMALL\n");
            printf("%d\n",v.size());
            reverse(v.begin(),v.end());
            for(auto it:v){
                printf("%c","PR"[it]);
            }
            printf("\n");
        }
    }
}
/*
2 11 14
9 3


000111222
001112220
*/