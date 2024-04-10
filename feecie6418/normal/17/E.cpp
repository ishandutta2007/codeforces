#include<bits/stdc++.h>
using namespace std;
const int mod=51123987;
char str[2000005];
int n,lst,s[2000005],fail[2000005],len[2000005],num[2000005],f[2000005],tot,cnt,ans=0,i,sum;
struct P{
	int x,y;
};
vector<P> ch[2000005];
int N(int x){
	++cnt,ch[cnt].clear(),fail[cnt]=0;
	return len[cnt]=x,cnt;
}
void Upd(int p,int c,int q){
	for(P&x:ch[p])if(x.x==c)return x.y=q,void();
	ch[p].push_back({c,q});
}
int Ch(int p,int c){
	for(P x:ch[p])if(x.x==c)return x.y;
	return 0;
}
void Clear(){
	tot=cnt=0;
	N(0),N(-1),s[0]=-1,fail[1]=fail[2]=2,lst=1;
	for(int i=0;i<26;i++)Upd(1,i,1),Upd(2,i,1);
}
int Ins(int c){
	int now,p=lst;
	s[++tot]=c;
	while(s[tot-len[p]-1]^c)p=fail[p];
	if(Ch(p,c)<=1){
		now=N(len[p]+2);
		int t=fail[p];
		while(s[tot-len[t]-1]^c)t=fail[t];
		fail[now]=Ch(t,c),Upd(p,c,now),num[now]=num[fail[now]]+1;
	}
	lst=Ch(p,c);
	return num[lst];
}
int main(){
	scanf("%d%s",&n,str+1),Clear();
	for(int i=1;i<=n;i++)f[i]=Ins(str[i]-'a');
	Clear();
	for(i=n,sum=0;i>=1;i--){
		ans=(ans+1ll*f[i]*sum)%mod;
		sum=(sum+Ins(str[i]-'a'))%mod;
	}
	cout<<(1ll*sum*(sum-1)/2%mod-ans+mod)%mod;
	return 0;
}