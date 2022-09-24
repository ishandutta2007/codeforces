#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
char str[1000005],a[1000005];
int n,lst,ch[1000005][30],s[1000005],fail[1000005],len[1000005],tot,cnt,f[1000005];
int slink[1000005],sum[1000005],diff[1000005],smallen[1000005];
int N(int x){
	return len[++cnt]=x,cnt;
}
void Clear(){
	memset(ch,0,sizeof(ch)),memset(fail,0,sizeof(fail)),tot=cnt=0;
	N(0),N(-1),s[0]=-1,fail[1]=fail[2]=2,lst=1;
	for(int i=0;i<26;i++)ch[1][i]=ch[2][i]=1;
}
void Ins(int c){
	int p=lst;
	s[++tot]=c;
	while(s[tot-len[p]-1]^c)p=fail[p];
	if(ch[p][c]<=1){
		int t=fail[p],x=N(len[p]+2);
		while(s[tot-len[t]-1]^c)t=fail[t];
		fail[x]=ch[t][c],ch[p][c]=x,diff[x]=len[x]-len[fail[x]];
		if(diff[x]==diff[fail[x]])slink[x]=slink[fail[x]],smallen[x]=smallen[fail[x]];
		else slink[x]=fail[x],smallen[x]=len[x];
	}
	lst=ch[p][c];
}
int main(){
	scanf("%s",str+1),Clear(),n=strlen(str+1);
	for(int i=1,j=n,cnt=1;cnt<=n;cnt++){
		if(cnt%2==1)a[cnt]=str[i++];
		else a[cnt]=str[j--];
	}
	f[0]=1;
	for(int i=1;i<=n;i++){
		Ins(a[i]-'a');
		for(int p=lst;len[p]>0;p=slink[p]){
			sum[p]=f[i-smallen[p]];
			if(slink[p]!=fail[p])sum[p]=(sum[p]+sum[fail[p]])%mod;
			if(i%2==0)f[i]=(f[i]+sum[p])%mod;
		}
	}
	cout<<f[n];
	return 0;
}