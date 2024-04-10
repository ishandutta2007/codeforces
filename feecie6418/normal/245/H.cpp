#include<bits/stdc++.h>
using namespace std;
char str[5005];
int n,q,lst,ch[5005][30],s[5005],fail[5005],len[5005],num[5005],tot,cnt,ans[5005][5005];
int N(int x){
	++cnt,memset(ch[cnt],0,sizeof(ch[cnt])),fail[cnt]=0;
	return len[cnt]=x,cnt;
}
void Clear(){
	tot=cnt=0;
	N(0),N(-1),s[0]=-1,fail[1]=fail[2]=2,lst=1;
	for(int i=0;i<26;i++)ch[1][i]=ch[2][i]=1;
}
int Ins(int c){
	int now,p=lst;
	s[++tot]=c;
	while(s[tot-len[p]-1]^c)p=fail[p];
	if(ch[p][c]<=1){
		now=N(len[p]+2);
		int t=fail[p];
		while(s[tot-len[t]-1]^c)t=fail[t];
		fail[now]=ch[t][c],ch[p][c]=now,num[now]=num[fail[now]]+1;
	}
	lst=ch[p][c];
	return num[lst];
}
int main(){
	scanf("%s%d",str+1,&q),n=strlen(str+1);
	for(int i=1;i<=n;i++){
		Clear();
		for(int j=i;j<=n;j++)ans[i][j]=ans[i][j-1]+Ins(str[j]-'a');
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",ans[l][r]);
	}
	return 0;
}