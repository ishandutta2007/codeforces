#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int cnt[1005];
int C[1005][1005];
int mod=1e9+7;
int cal(char *c,int k,int len){
	if(len<k){
		return 0;
	}
	if(len==k){
		for(int i=0;c[i]!=0;i++)
		if(c[i]=='0')
		return 0;
		return 1;
	}
	if(k==0){
		return 1;
	}
	if(c[0]=='0')
	return cal(c+1,k,len-1);
	else
	return (C[len-1][k]+cal(c+1,k-1,len-1))%mod;
}
int main(){
	for(int i=0;i<1005;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=1;i<=1000;i++){
		cnt[i]=0;
		int k=i;
		while(k!=1){
			int x=0;
			while(k){
				if(k&1)x++;
				k>>=1;
			}
			k=x;
			cnt[i]++;
		}
	}
	char c[1005];
	scanf("%s",c);
	int k;
	scanf("%d",&k);
	if(k==0){
		printf("1\n");
	}
	else{
		int len=strlen(c);
		int ans=0;
		for(int i=1;i<=1000;i++){
			if(cnt[i]==k-1){
			//	printf("%d\n",i);
				ans+=cal(c,i,len);
			//	printf("%d\n",ans);
				ans%=mod;
			}
		}
		if(k==1)
		ans--;
		printf("%d\n",ans);
	}
}