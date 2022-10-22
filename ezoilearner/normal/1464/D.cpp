#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
const int Mod=1000000007;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n;
#define Maxn 1000010
#define cout cerr
#define FR first
#define SE second
int p[Maxn];
bool vis[Maxn];int cnt[5];

int mul(int a,int b){return 1ll*a*b%Mod;}
int Fast_Pow(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%Mod;
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return res;
}

int calc(int c1,int c2){
	if(c2>=c1)return c2;
	return c2+(c1-c2)/3*2;
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;rd(T);
	while(T--){
		int ans=0;
		rd(n);
		memset(vis,false,sizeof(bool)*(n+1));
		memset(cnt,0,sizeof(cnt));
		rep(i,1,n)rd(p[i]);
		rep(i,1,n)
			if(!vis[i]){
				int j=i,len=0;
				while(!vis[j]){
					vis[j]=true;
					len++;
					j=p[j];
				}
				if(len==1)cnt[1]++;
				else if(len%3==0)cnt[3]++,ans+=len/3-1;
				else if(len%3==1)cnt[4]++,ans+=len/3-1;
				else cnt[2]++,ans+=len/3;
			}
		if(n==4){
			printf("4 ");
			if(cnt[3])puts("1");
			else if(cnt[4])puts("0");
			else if(cnt[2]==2)puts("0");
			else if(cnt[2]==1&&cnt[1]==2)puts("1");
			else puts("2");
		}else{
			if(n%3==0){
				printf("%d ",Fast_Pow(3,n/3));
				cnt[1]+=cnt[4];ans+=cnt[4];
				ans+=calc(cnt[1],cnt[2]);
			}else if(n%3==2){
				printf("%d ",mul(2,Fast_Pow(3,n/3)));
				cnt[1]+=cnt[4];ans+=cnt[4];
				int ret1=inf,ret2=inf;
				if(cnt[1]>=2)ret1=1+calc(cnt[1]-2,cnt[2]);
				if(cnt[2]>=1)ret2=calc(cnt[1],cnt[2]-1);
				ans+=min(ret1,ret2);
			}else{
				printf("%d ",mul(4,Fast_Pow(3,n/3-1)));
				int ret1=inf,ret2=inf,ret3=inf,ret4=inf;
				if(cnt[4]){
					ret1=cnt[4]-1+calc(cnt[1]+cnt[4]-1,cnt[2]);
					ret1=min(ret1,cnt[4]+calc(cnt[1]+cnt[4]-1,cnt[2]));
				}
				if(cnt[3]&&cnt[1])ret2=cnt[4]+1+calc(cnt[1]-1+cnt[4],cnt[2]);
				if(cnt[2]>=2)ret3=cnt[4]+calc(cnt[1]+cnt[4],cnt[2]-2);
				if(cnt[2]>=1&&cnt[1]>=2)ret3=min(ret3,1+cnt[4]+calc(cnt[1]-2+cnt[4],cnt[2]-1));
				if(cnt[1]>=4)ret4=2+cnt[4]+calc(cnt[1]-4+cnt[4],cnt[2]);
				ans+=min(min(ret1,ret2),min(ret3,ret4));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}