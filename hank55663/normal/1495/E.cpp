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
LL seed=0;
LL base=0;
const int mod=1e9+7;
LL rnd(){
	LL ret=seed;
	seed=(seed*base+233)%mod;
	return ret;
}
int p[200005];
int k[200005];
int b[200005];
int w[200005];
int a[5000005];
int t[5000005];
int cnt[5000005];
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=m;i++)scanf("%d %d %d %d",&p[i],&k[i],&b[i],&w[i]);
	LL ans[2]={0,0};//,ans2=0;
	p[0]=0;
	for(int i = 1;i<=m;i++){
		seed=b[i];
		base=w[i];
		for(int j =p[i-1]+1;j<=p[i];j++){
			t[j]=(rnd()%2);
			a[j]=(rnd()%k[i])+1;
			ans[t[j]]+=a[j];
			//printf("%d %d\n",a[j],t[j]);
		}
	}
	//for(int i = 1;i<=n;i++)scanf("%d %d",&t[i],&a[i]),ans[t[i]]+=a[i];
	if(ans[0]==ans[1]||ans[t[1]]==ans[1-t[1]]+1){
		LL res=1;
		for(LL i = 1;i<=n;i++){
			res=res*(((a[i]^(i*i))+1)%mod)%mod;
		}
		printf("%lld\n",res);
	}
	else{
		if(ans[t[1]]<ans[1-t[1]]){
			LL tot=0;
			for(int i = 1;i<=n;i++){
				if(t[i]==t[1])tot+=a[i],cnt[i]+=a[i],a[i]=0;
				else{
					if(tot>=a[i]){
						tot-=a[i];
						cnt[i]+=a[i];
						a[i]=0;
					}
					else{
						a[i]-=tot;
						cnt[i]+=tot;
						tot=0;
					}
				}
			}
			for(int i = 1;i<=n;i++){
				if(t[i]!=t[1]){
					if(tot>=a[i]){
						tot-=a[i];
						cnt[i]+=a[i];
						a[i]=0;
					}
					else{
						a[i]-=tot;
						cnt[i]+=tot;
						tot=0;
					}
				}
			}
		}
		else{
			a[1]--;
			cnt[1]++;
			int st=-1;
			for(int j =1;j<=n;j++){
				if(t[j]!=t[1]){
					st=j;
					break;
				}
			}
			//printf("%d\n",st);
			if(st!=-1){
				int i=st;
				LL tot=0;
				do{
					if(t[i]==t[st])tot+=a[i],cnt[i]+=a[i],a[i]=0;
					else{
						if(tot>=a[i]){
							tot-=a[i];
							cnt[i]+=a[i];
							a[i]=0;
						}
						else{
							a[i]-=tot;
							cnt[i]+=tot;
							tot=0;
						}
					}
					i=i%n+1;
				}while(i!=st);
				do{
					if(t[i]==t[st]);//tot+=a[i],cnt[i]=a[i],a[i]=0;
					else{
						if(tot>=a[i]){
							tot-=a[i];
							cnt[i]+=a[i];
							a[i]=0;
						}
						else{
							a[i]-=tot;
							cnt[i]+=tot;
							tot=0;
						}
					}
					i=i%n+1;
				}while(i!=st);
			}
		}
		LL res=1;
		for(LL i = 1;i<=n;i++){
			//printf("%d ",cnt[i]);
			res=res*(((cnt[i]^(i*i))+1)%mod)%mod;
		}
		printf("%lld\n",res);
	}
}
/*
5 5
2 8
*/
int main(){
		//MEMS(dp);
	int t=1;0000;//000000;//000000;
    //scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}