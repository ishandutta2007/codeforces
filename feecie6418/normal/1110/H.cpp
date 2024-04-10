#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
char L[805],R[805];
int ch[17005][10],s[17005][2005],f[2005][17005],fail[17005],n,lenl,lenr,tot=0;
bitset<17005> is[2005];
void Build1(){
	int p=0;
	for(int i=1;i<=lenl;i++){
		int wl=L[i]-'0',wr=R[i]-'0';
		if(wl==wr){
			ch[p][wl]=++tot;
			p=ch[p][wl];
			if(i==lenl)s[p][0]++;
			continue;
		}
		for(int j=wl+1;j<wr;j++)ch[p][j]=++tot,s[tot][lenl-i]++;
		ch[p][wl]=++tot;
		ch[p][wr]=++tot;
		int q=ch[p][wl],j=i+1;
		while(j<=lenl){
			int w=L[j]-'0';
			ch[q][w]=++tot;
			for(int k=w+1;k<10;k++)ch[q][k]=++tot,s[tot][lenl-j]++;
			q=ch[q][w],j++;
		}
		s[q][0]++;
		q=ch[p][wr],j=i+1;
		while(j<=lenl){
			int w=R[j]-'0';
			ch[q][w]=++tot;
			for(int k=0;k<w;k++)ch[q][k]=++tot,s[tot][lenl-j]++;
			q=ch[q][w],j++;
		}
		s[q][0]++;
		break;
	}
}
void Build2(){
	int p=0;
	for(int i=1;i<=lenl;i++){
		int w=L[i]-'0';
		for(int j=w+1;j<10;j++)ch[p][j]=++tot,s[tot][lenl-i]++;
		ch[p][w]=++tot;
		p=ch[p][w];
	}
	s[p][0]++;
	p=0;
	for(int i=1;i<=lenr;i++){
		int w=R[i]-'0';
		for(int j=0;j<w;j++){
			if(i==1&&j==0)continue;
			if(!ch[p][j])ch[p][j]=++tot;
			s[ch[p][j]][lenr-i]++;
		}
		if(!ch[p][w])ch[p][w]=++tot;
		p=ch[p][w];
	}
	s[p][0]++;
}
void upd(int &x,int y){
	x=max(x,y);
}
int main(){
	cin>>L+1>>R+1>>n;
	lenl=strlen(L+1),lenr=strlen(R+1);
	if(lenl==lenr)Build1();
	else Build2();
//	for(int i=0;i<=tot;i++){
//		for(int j=0;j<10;j++){
//			if(ch[i][j])printf("ch[%d][%d]=%d\n",i,j,ch[i][j]);
//		}
//		for(int j=0;j<=n;j++){
//			if(s[i][j])printf("s[%d][%d]=%d\n",i,j,s[i][j]);
//		}
//		//printf("fail[%d]=%d\n",i,fail[i]);
//	}
	queue<int> q;
	for(int i=0;i<10;i++)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<=n;i++)s[x][i]+=s[fail[x]][i];
		for(int i=0;i<10;i++){
			if(ch[x][i])q.push(ch[x][i]),fail[ch[x][i]]=ch[fail[x]][i];
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	for(int i=0;i<=tot;i++)for(int j=1;j<=n;j++)s[i][j]+=s[i][j-1];
	memset(f,0xc0,sizeof(f)),f[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=tot;j++){
			for(int k=0;k<10;k++){
				upd(f[i+1][ch[j][k]],f[i][j]+s[ch[j][k]][n-i-1]);
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)if(i-j+1>lenl&&i-j+1<lenr)sum++;
	}
	int mx=*max_element(f[n],f[n]+tot+1);
	cout<<sum+mx<<'\n';
	for(int j=0;j<=tot;j++)if(f[n][j]==mx)is[n][j]=1;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<=tot;j++){
			for(int k=0;k<10;k++){
				if(is[i+1][ch[j][k]]&&f[i][j]+s[ch[j][k]][n-i-1]==f[i+1][ch[j][k]]){
					is[i][j]=1;
				}
			}
		}
	}
	for(int i=1,p=0;i<=n;i++){
		for(int j=0;j<10;j++)
			if(is[i][ch[p][j]]&&f[i-1][p]+s[ch[p][j]][n-i]==f[i][ch[p][j]]){
				cout<<j,p=ch[p][j];
				break;
			}
	}
}