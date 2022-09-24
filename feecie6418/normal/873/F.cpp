#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fa[400005],c[400005][26],len[400005],s[400005],lst=1,tot=1,n,p[400005],sum[400005];
char a[200005],b[200005];
ll ans=0;
void Ins(int w){
	int x=++tot,p=lst;
	lst=x,len[x]=len[p]+1;
	for(;p&&!c[p][w];p=fa[p])c[p][w]=x;
	if(!p)return fa[x]=1,void();
	int q=c[p][w];
	if(len[p]+1==len[q])return fa[x]=q,void();
	int nq=++tot;
	memcpy(c[nq],c[q],sizeof(c[q])),fa[nq]=fa[q],fa[x]=fa[q]=nq,len[nq]=len[p]+1;
	for(;p&&c[p][w]==q;p=fa[p])c[p][w]=nq;
}
int main() {
	scanf("%d%s%s",&n,a+1,b+1);
	for(int i=1;i<=n;i++){
		Ins(a[i]-'a');
		if(b[i]=='0')s[lst]=1;
	}
	for(int i=1;i<=tot;i++)sum[len[i]]++;
	for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
	for(int i=tot;i>=1;i--)p[sum[len[i]]--]=i;
	for(int i=tot;i>=1;i--)s[fa[p[i]]]+=s[p[i]];
	for(int i=1;i<=tot;i++)ans=max(ans,1ll*s[i]*len[i]);
	cout<<ans;
	return 0;
}