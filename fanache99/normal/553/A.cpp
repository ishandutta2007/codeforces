#include<cstdio>
#define mod 1000000007
using namespace std;
long long sol[1010];
int c[1010],s[1010];
long long expo(int baza,int exp){
	long long rez=1;
	while(exp!=0)
		if(exp%2==1){
			rez=(1LL*rez*baza)%mod;
			exp--;
		}
		else{
            baza=(1LL*baza*baza)%mod;
            exp/=2;
		}
	return rez;
}
long long comb(int n,int k){
    if(k==0)
        return 1;
    long long sol=1;
    int i;
    for(i=n-k+1;i<=n;i++){
        sol*=i;
        sol%=mod;
    }
    for(i=1;i<=k;i++){
        sol*=expo(i,mod-2);
        sol%=mod;
    }
    return sol;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int n,i;
    scanf("%d",&n);
    sol[0]=1;
    for(i=1;i<=n;i++){
        scanf("%d",&c[i]);
        s[i]=c[i]+s[i-1];
        sol[i]=sol[i-1]*comb(s[i]-1,c[i]-1);
        sol[i]%=mod;
    }
    printf("%I64d",sol[n]);
    return 0;
}