#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=2e5+100,mod=998244353,maxn=2e5;
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

int pri[N];bool bz[N];

int Cnt[N],Max[N],Len[N],b1[N][15],b2[N][15],g[N];bool bk[N];
struct edge{
	int x,y,c1,c2,next;
}a[2*N];int len,last[N];
void ins(int x,int y,int c1,int c2){
	a[++len].x=x;a[len].y=y;
	a[len].c1=c1;a[len].c2=c2;
	a[len].next=last[x];last[x]=len;
}

void dfs(int x){
	bk[x]=false;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y,c1=a[k].c1,c2=a[k].c2;
		if(bk[y]){
			for(int i=1;i<=Len[c1];i++){
				Cnt[b1[c1][i]]+=b2[c1][i];
			}
			for(int i=1;i<=Len[c2];i++){
				Cnt[b1[c2][i]]-=b2[c2][i];
			}
			for(int i=1;i<=Len[c1];i++)
				if(Max[b1[c1][i]]<Cnt[b1[c1][i]]) Max[b1[c1][i]]=Cnt[b1[c1][i]];
			g[y]=(ll)g[x]*ni(c1)%mod*c2%mod;
			dfs(y);
			for(int i=1;i<=Len[c1];i++){
				Cnt[b1[c1][i]]-=b2[c1][i];
			}
			for(int i=1;i<=Len[c2];i++){
				Cnt[b1[c2][i]]+=b2[c2][i];
			}
		}
	}
}


int main()
{
	
	for(int i=2;i<=maxn;i++){
		if(!bz[i]) pri[++pri[0]]=i;
		for(int j=1;j<=pri[0];j++){
			if(maxn/i<pri[j]) break;
			bz[i*pri[j]]=true;
			if(i%pri[j]==0) break;
		}
	}
	memset(Len,0,sizeof(Len));
	for(int i=2;i<=maxn;i++)
		if(!bz[i])
			for(int j=i;j<=maxn;j+=i){
				b1[j][++Len[j]]=i;
				int e=j;
				while(e%i==0) e/=i,b2[j][Len[j]]++;
			}
	
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		len=0;
		for(int i=1;i<=n;i++) last[i]=0;
		for(int i=1;i<n;i++){
			int x,y,c1,c2;
			scanf("%d%d%d%d",&x,&y,&c1,&c2);
			ins(x,y,c1,c2);ins(y,x,c2,c1);
		}
		
		for(int i=1;i<=n;i++) bk[i]=true,Cnt[i]=Max[i]=0;
		g[1]=1;dfs(1);
		
		int Ans=0,d=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=Max[i];j++) d=(ll)d*i%mod;
		for(int i=1;i<=n;i++)
			Ans=(Ans+(ll)d*g[i])%mod;
		printf("%d\n",Ans);
	}
	
	return 0;
}