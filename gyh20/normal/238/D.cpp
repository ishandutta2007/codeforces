//copied from D2019YJY
#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
int read(){
	int g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
const int N=100005;
const int INF=0x3f3f3f3f;
int n,T,l[N],r[N],tot,ans[N*10][10],t[N],pre[N];
set<int>f[N];
char s[N];
int main(){
	n=read(),T=read();
	scanf("%s",s+1);
	s[0]='#';
	for(int i=0;i<=n;i++)l[i]=i-1,r[i]=i+1;
	int x=0,fx=1;
	while(x<=n){
		int last=x;
		x=fx?r[x]:l[x];
		tot++;
		f[x].insert(tot);
		memcpy(ans[tot],ans[tot-1],sizeof(ans[tot]));
		if(!t[x])t[x]=tot,pre[x]=l[x];
		if('0'<=s[x]&&s[x]<='9'){
			ans[tot][s[x]-'0']++;
			if(s[x]=='0'){
				l[r[x]]=l[x];
				r[l[x]]=r[x];
				if(t[x]==tot)pre[x]=l[x];
			}
			else s[x]--;
		}
		else{
			if((s[last]<'0'||'9'<s[last])&&s[last]!='#'){
				l[r[last]]=l[last];
				r[l[last]]=r[last];
				if(t[x]==tot)pre[x]=l[x];
			}
			fx=s[x]=='<'?0:1;
		}
	}
	while(T--){
		int x=read(),y=read();
		set<int>::iterator it=f[pre[x]].lower_bound(t[x]);
		int t1=(it==f[pre[x]].end())?INF:*it,t2=t[x]-1;
		t1=min(t1,t[y+1])-1;
		for(int i=0;i<=9;i++)cout<<ans[t1][i]-ans[t2][i]<<' ';
		cout<<'\n';
	}
	return 0;
}