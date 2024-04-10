#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define int long long
int n,m,T,cz[N][2],hf[N],len,a[N],j,cnt,tot,fl,gg,X,i,vis[N];
map<int,int>p;
void add(int x,int y){
	for(int i=len;i>=x;--i)a[i+2]=a[i];
	a[x+1]=a[x+2]=y;len+=2;
	cz[++tot][0]=x,cz[tot][1]=y;
}
void solve(int l,int r){
	if(l>r)return ;
	int i,pos;
	for(i=l+1;i<=r;++i){
		if(a[i]==a[l]){pos=i;break;}
	}
	for(i=l+1;i<pos;++i){
		add(i-l-1+pos,a[i]);
	}
	hf[++cnt]=pos*2-l-1;
	solve(pos*2-l,len);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;fl=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=1;i<=n;++i)++p[a[i]];
		for(i=1;i<=n;++i)if((p[a[i]]&1))fl=1;
		p.clear();
		if(fl)cout<<"-1\n";
		else{
			tot=cnt=0;len=n;solve(1,n);cout<<tot<<"\n";
			for(i=1;i<=tot;++i)cout<<cz[i][0]<<" "<<cz[i][1]<<"\n";
			cout<<cnt<<"\n";
			for(i=1;i<=cnt;++i)cout<<hf[i]-hf[i-1]<<"\n";
		}
	}
}