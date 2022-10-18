#include <bits/stdc++.h>
#define ll long long
int ch[50005][13],link[50005],n,tail=0,lm1[55],lm2[55],fini[50005],N,f[55][50005][2][2];
char s[1005],s1[1005],s2[1005];
const int mod=1e9+7;
 
void insert(int l,int r){
	int rt=0;
	for(int i=l;i<=r;++i){
		if (!ch[rt][s[i]-'0'])ch[rt][s[i]-'0']=++tail;
		rt=ch[rt][s[i]-'0'];
	}fini[rt]=1;
}
 
void build(){
	std::queue<int>q;
	std::memset(link,-1,sizeof(link));
	for(int i=0;i<10;++i)if (ch[0][i]){link[ch[0][i]]=0;q.push(ch[0][i]);}
	while (!q.empty()){
		int u=q.front();q.pop();
		fini[u]|=fini[link[u]];
		for(int i=0;i<10;++i){
			if (ch[u][i]&&link[ch[u][i]]==-1){
				link[ch[u][i]]=ch[link[u]][i];
				q.push(ch[u][i]);
			}else ch[u][i]=ch[link[u]][i];
		}
	}
}
void inc(int &x,int y){x=(x+y)%mod;}
int calc(int *lm,int flag=0){
	int ans=0;
	std::memset(f,0,sizeof(f));
	f[1][0][1][0]=1;
	for(int i=1;i<=N;++i)
	for(int j=0;j<=tail;++j)
	for(int k=0+(i==1);k<10;++k){
		if (k<lm[i])for(int s=0;s<=1;++s)inc(f[i+1][ch[j][k]][0][s|fini[ch[j][k]]],f[i][j][0][s]+f[i][j][1][s]);
		else if (k==lm[i]){
			for(int s=0;s<=1;++s){
				inc(f[i+1][ch[j][k]][0][s|fini[ch[j][k]]],f[i][j][0][s]);
				inc(f[i+1][ch[j][k]][1][s|fini[ch[j][k]]],f[i][j][1][s]);
			}
		} else if (k>lm[i])
			for(int s=0;s<=1;++s)inc(f[i+1][ch[j][k]][0][s|fini[ch[j][k]]],f[i][j][0][s]);
	}for(int j=0;j<=tail;++j)inc(ans,f[N+1][j][0][1]+f[N+1][j][1][1]);
	if (flag){
		int det=0,rt=0;
		for(int i=1;i<=N;++i){rt=ch[rt][lm[i]];det|=fini[rt];}
		ans=(ans-det+mod)%mod;
	}
	return ans;
}
 
int main(){
	scanf("%s%s%s",s+1,s1+1,s2+1);
	n=std::strlen(s+1);N=std::strlen(s1+1);
	for(int i=1;i<=N;++i)lm1[i]=s1[i]-'0',lm2[i]=s2[i]-'0';
	for(int i=1;i+N/2-1<=n;++i)insert(i,i+N/2-1);
	build();
	std::cout<<(calc(lm2)-calc(lm1,1)+mod)%mod;
	return 0;
}