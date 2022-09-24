#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,inf=1e9;
typedef pair<int,int> pr;
char A[1000005],B[1000005],a[1000005];
int n,lst,ch[1000005][30],s[1000005],fail[1000005],len[1000005],tot,cnt;
int slink[1000005],diff[1000005],smallen[1000005];
pr f[1000005],sum[1000005];
int N(int x){
	return len[++cnt]=x,sum[cnt]=pr(inf,0),cnt;
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
	scanf("%s%s",A+1,B+1),Clear(),n=strlen(A+1)*2;
	for(int i=1;i<=n/2;i++){
		a[i*2-1]=A[i];
		a[i*2]=B[i];
	}
	f[0]=pr(0,0);
	for(int i=1;i<=n;i++){
		Ins(a[i]-'a'),f[i]=pr(inf,0);
		for(int p=lst;len[p]>0;p=slink[p]){
			sum[p]=pr(f[i-smallen[p]].first,i-smallen[p]);
			if(slink[p]!=fail[p])sum[p]=min(sum[p],sum[fail[p]]);
			if(i%2==0)f[i]=min(f[i],pr(sum[p].first+1,sum[p].second));
		}
		if(i>=2&&a[i]==a[i-1])f[i]=min(f[i],pr(f[i-2].first,i-2));
	}
	if(f[n].first>=inf)puts("-1");
	else {
		cout<<f[n].first<<'\n';
		int t=n;
		while(t){
			if(f[t].second!=t-2)cout<<(f[t].second+2)/2<<' '<<t/2<<'\n';
			t=f[t].second;
		}
	}
}