#include <bits/stdc++.h>
#define maxn 500005
char s[maxn];
long long ans[maxn];
int n;
struct palindromicTree {
	int s[maxn],link[maxn],len[maxn],ch[maxn][26],cnt[maxn],tail,now,n,half[maxn],f[maxn];
	void reset(){s[0]=-1;tail=1;len[0]=0;len[1]=-1;link[0]=1;now=0;n=0;}
	int find(int x){
		while (s[n]!=s[n-len[x]-1])x=link[x];
		return x;
	}void extend(int x){
		s[++n]=x;
		int p=find(now);
		if (!ch[p][x]){
			link[++tail]=ch[find(link[p])][x];
			ch[p][x]=tail;
			len[tail]=len[p]+2;
		}now=ch[p][x];cnt[now]++;
	}void calc_cnt(){
		for(int i=tail;i>=0;i--){cnt[link[i]]+=cnt[i];half[i]=i;}
		for(int i=tail;i>=2;i--){
			while (len[half[i]]>len[i]/2)half[i]=link[half[i]];
			if (len[half[i]]<len[half[link[i]]])half[link[i]]=half[i];
		}for(int i=2;i<=tail;++i){
			f[i]=1;
			if (len[half[i]]==len[i]/2)f[i]=f[half[i]]+1;
			ans[f[i]]+=cnt[i];
		}
	}
}pam;

int main(){
	pam.reset();scanf("%s",s+1);
	n=std::strlen(s+1);
	for(int i=1;i<=n;++i)pam.extend(s[i]-'a');
	pam.calc_cnt();
	for(int i=n-1;i>=1;i--)ans[i]+=ans[i+1];
	for(int i=1;i<=n;++i)std::cout<<ans[i]<<" ";
	return 0;
}