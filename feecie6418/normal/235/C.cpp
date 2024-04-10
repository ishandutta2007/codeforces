#include<bits/stdc++.h>
using namespace std;
#define size sz
int fa[2000005],ch[2000005][26],len[2000005],lst=1,tot=1,n,q,vst[2000005],cl[2000005],s[2000005],r[2000005],size[2000005];
char str[2000005];
void Insert(int c){
	int now=++tot,p=lst;
	len[now]=len[lst]+1,lst=now;
	while(p&&!ch[p][c])ch[p][c]=now,p=fa[p];
	if(!p)return fa[now]=1,void();
	int q=ch[p][c];
	if(len[q]==len[p]+1)return fa[now]=q,void();
	int nq=++tot;
	memcpy(ch[nq],ch[q],sizeof(ch[q]));
	len[nq]=len[p]+1,fa[nq]=fa[q],fa[q]=fa[now]=nq;
	while(p&&ch[p][c]==q)ch[p][c]=nq,p=fa[p];
	return ;
} 
int main() {
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)Insert(str[i]-'a'),size[lst]++;
	for(int i=1;i<=tot;i++)s[len[i]]++;
	for(int i=1;i<=n;i++)s[i]+=s[i-1];
	for(int i=tot;i>=1;i--)r[s[len[i]]--]=i;
	for(int i=tot;i>=1;i--)size[fa[r[i]]]+=size[r[i]];
	scanf("%d",&q);
	while(q--){
		scanf("%s",str+1);
		int l=strlen(str+1),ans=0;
		for(int i=1;i<l;i++)str[i+l]=str[i];
		for(int i=1,now=1,nowl=0;i<=2*l-1;i++){
			char c=str[i]-'a';
			if(ch[now][c])now=ch[now][c],nowl++;
			else {
				while(now&&!ch[now][c])now=fa[now];
				if(!now)now=1,nowl=0;
				else nowl=len[now]+1,now=ch[now][c];
			}
			while(nowl>l&&len[fa[now]]>=l)now=fa[now],nowl=len[now];
			if(nowl>=l&&!vst[now])nowl=len[now],vst[now]=1,ans+=size[now],cl[++cl[0]]=now;
		}
		while(cl[0])vst[cl[cl[0]--]]=0;
		printf("%d\n",ans);
	}
	return 0;
}