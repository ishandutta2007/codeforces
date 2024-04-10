#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int MAXL=1<<22;
char i_str[MAXL],*i_s,*i_t;
char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
int read() {
	int x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=x*10+(ch^48);
	return f?-x:x;
}
const int maxn=2e5+10;
int f[maxn],deg[maxn];
vector<int>to[maxn];
unordered_map<int,int>s[maxn];
int sk[maxn],top,k,c[maxn],n,m;
int check(int x) {
	if(1ll*k*(k-1)/2>m)return 0;
	sk[top=1]=x;
	for(int y:to[x])
		if(f[y]<=1) {
			sk[++top]=y;
			if(deg[y]<k-1)return 0;
		}
	if(top<k)return 0;
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
			if(!s[sk[i]].count(sk[j]))return 0;
	printf("2\n%d",x);
	for(int i=2;i<=k;i++)
		printf(" %d",sk[i]);
	puts("");
	return 1;
}
queue<int>q;
int main() {
//	freopen("data.in","r",stdin);
	int T=read(),a,b;
	while(T--) {
		int FL=0;
		n=read(),m=read(),k=read();
		while(!q.empty())q.pop();
		for(int i=1;i<=n;i++) {
			c[i]=f[i]=deg[i]=0;
			to[i].clear();
			s[i].clear();
		}
		for(int i=1;i<=m;i++) {
			a=read(),b=read();
			to[a].push_back(b);
			to[b].push_back(a);
			s[a][b]=s[b][a]=1;
			deg[a]++;
			deg[b]++;
		}
		for(int i=1;i<=n;i++)
			if(deg[i]<k) {
				f[i]=1;
				q.push(i);
			}
		int cnt=0;
		while(!q.empty()) {
			cnt++;
			int x=q.front();
			q.pop();
			f[x]=2;
			if(deg[x]==k-1&&check(x)) {
				FL=1;
				break;//saugyfdghsj
			}
			for(int y:to[x]) {
				if(--deg[y]<k&&!f[y]) {
					f[y]=1;
					q.push(y);
				}
			}
		}
		if(FL)continue;
		if(cnt<n) {
			printf("1 %d\n",n-cnt);
			for(int i=1;i<=n;i++)
				if(!f[i])printf("%d ",i);
			puts("");
			continue;
		} else puts("-1");
	}
	return 0;
}