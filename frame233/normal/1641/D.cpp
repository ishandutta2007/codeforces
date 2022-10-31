#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef __int128 LL;typedef long long ll;
int t[N*5],a[N][5],pos,w[N];LL all[N*32];int ap,T[N],v[N][32],W[N],nc,n,m,cnt[N*32],C[32];
bool check(int i){
	int sum=0;for(int st=0;st<1<<m;++st)sum+=C[st]?-cnt[v[i][st]]:cnt[v[i][st]];
	return sum>0;
}
int main(){
	for(int i=1;i<32;++i)C[i]=C[i>>1]^(i&1);
	read(n,m);
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j)read(a[i][j]),t[++pos]=a[i][j];
		read(w[i]),T[i]=i;
	}
	std::sort(T+1,T+n+1,[&](int x,int y){return w[x]<w[y];});
	std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<m;++j)a[i][j]=std::lower_bound(t+1,t+pos+1,a[i][j])-t;
		std::sort(a[i],a[i]+m);
		for(int st=0;st<1<<m;++st){
			LL cur=0;for(int j=0;j<m;++j)if(st>>j&1)cur=cur*500001LL+a[i][j];
			all[++ap]=cur;
		}
	}
	std::sort(all+1,all+ap+1),ap=std::unique(all+1,all+ap+1)-all-1;
	for(int _=1;_<=n;++_){
		int i=T[_];
		for(int st=0;st<1<<m;++st){
			LL cur=0;for(int j=0;j<m;++j)if(st>>j&1)cur=cur*500001LL+a[i][j];
			v[_][st]=std::lower_bound(all+1,all+ap+1,cur)-all;
		}
		W[_]=w[i];
	}
	memset(cnt,0,sizeof(cnt));int ans=2e9+1;
	for(int i=1;i<=n;++i)for(int j=0;j<1<<m;++j)++cnt[v[i][j]];
	for(int i=1,j=n;i<=n;++i){
		while(check(i)){
			for(int k=0;k<1<<m;++k)--cnt[v[j][k]];
			--j;
		}
		if(j<n){++j;for(int k=0;k<1<<m;++k)++cnt[v[j][k]];}
		if(check(i))ans=std::min(ans,W[i]+W[j]);
	}
	printf("%d\n",ans>2e9?-1:ans);
	return 0;
}