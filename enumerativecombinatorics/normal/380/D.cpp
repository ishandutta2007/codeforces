#include<stdio.h>
#include<algorithm>
using namespace std;
int b[110000];
long long fact[310000];
long long factinv[310000];
long long inv[310000];
pair<int,int> ev[310000];
int main(){
    int a;
    int mod=1000000007;
    fact[0]=1;
    for(int i=1;i<310000;i++)fact[i]=fact[i-1]*i%mod;
    inv[1]=1;
    for(int i=2;i<310000;i++)inv[i]=(mod-(mod/i)*inv[mod%i]%mod);
    factinv[0]=1;
    for(int i=1;i<310000;i++)factinv[i]=factinv[i-1]*inv[i]%mod;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",b+i);
    }
    int best=9999999;
    int at=-1;
    for(int i=0;i<a;i++){
        if(b[i]&&best>b[i]){
            at=i;
            best=b[i];
        }
    }
    bool ok=true;
    int now=best;
    for(int i=at;i>=0;i--){
        if(b[i]){
            if(now>b[i]){
                ok=false;
            }
            now=b[i];
        }
    }
    now=best;
    for(int i=at;i<a;i++){
        if(b[i]){
            if(now>b[i]){
                ok=false;
            }
            now=b[i];
        }
    }
    if(!ok){
        printf("0\n");
        return 0;
    }
    int ind=0;
    
    for(int i=0;i<a;i++){
        if(b[i])ev[ind++]=make_pair(b[i],i);
    }
    std::sort(ev,ev+ind);
    //for(int i=0;i<ind;i++)printf("%d %d\n",ev[i].first,ev[i].second);
    int L=0;
    int R=a-1;
    long long ret=1;
    int last=a+1;
    if(ind==1){
        ret=0;
        int l=ev[0].second+1;
        int s=last-ev[0].first;
        int r=s-l;
        if(l>=1&&r>=0){
            ret=(ret+fact[s-1]%mod*factinv[r]%mod*factinv[s-1-r]%mod)%mod;
        }
        if(best!=1){
            r=R-ev[0].second+1;
            s=last-ev[0].first;
            l=s-r;
            if(r>=1&&l>=0){
                ret=(ret+fact[s-1]%mod*factinv[l]%mod*factinv[s-1-l]%mod)%mod;
            }
        }
        printf("%d\n",(int)ret);
        return 0;
    }
    for(int i=ind-1;i>=0;i--){
        if(ev[i].second<at){
            int l=ev[i].second-L+1;
            int s=last-ev[i].first;
            int r=s-l;
            if(l<1||r<0){ret=0;break;}
            ret=ret*fact[s-1]%mod*factinv[r]%mod*factinv[s-1-r]%mod;
            L=ev[i].second+1;
            last=ev[i].first;
            R-=r;
        }else if(ev[i].second>at){
            int r=R-ev[i].second+1;
            int s=last-ev[i].first;
            int l=s-r;
            if(r<1||l<0){ret=0;break;}
            ret=ret*fact[s-1]%mod*factinv[l]%mod*factinv[s-1-l]%mod;
            R=ev[i].second-1;
            last=ev[i].first;
            L+=l;
        }else{
            long long Ret=0;
            int l=ev[0].second-L+1;
            int s=last-ev[0].first;
            int r=s-l;
            long long val=1;
            for(int j=0;j<R-L-s;j++)val=val*2%mod;
            if(l>=1&&r>=0){
                Ret=(Ret+fact[s-1]%mod*factinv[r]%mod*factinv[s-1-r]%mod*val%mod)%mod;
            }
            if(best!=1){
                r=R-ev[0].second+1;
                s=last-ev[0].first;
                l=s-r;
                if(r>=1&&l>=0){
                    Ret=(Ret+fact[s-1]%mod*factinv[l]%mod*factinv[s-1-l]%mod*val%mod)%mod;
                }
            }
            ret=ret*Ret%mod;
            R=-1111;
        }
    //  printf("%d %d %d %d\n",i,L,R,(int)ret);
    }
    if(L<=R){
        for(int i=0;i<R-L;i++)ret=ret*2%mod;
    }
    printf("%d\n",(int)ret);
}