#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=5e3+12,mod=1e9+7;
int n,m;
int a[N],b[N];
vector<int>l[N],r[N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)a[i]=getint();
	int x,y,tmp=0;
	FOR(i,1,m){
		x=getint(),y=getint();
		tmp=y;
		FOR(j,1,n)if(a[j]==x&&!--tmp){
			l[x].push_back(j);break;
		}
		tmp=y;
		ROF(j,n,1)if(a[j]==x&&!--tmp){
			r[x].push_back(j);break;
		}
	}
}
int f0[N],f1[N];
int g0[N],g1[N];
int F0[N],F1[N];
int G0[N],G1[N];
int cnt[N];
V init(){
	FOR(i,1,n)g0[i]=1;
	g1[0]=1;
}
V check(int&x){x-=mod,x+=x>>31&mod;}
V work(){
	int x,y,z;
	FOR(i,1,n)if(!l[i].empty()){
		FOR(j,0,n)cnt[j]=F0[j]=G0[j]=F1[j]=G1[j]=0;
		for(int v:r[i])cnt[v]++;
		ROF(j,n,0)cnt[j]+=cnt[j+1];
		FOR(j,0,((int)l[i].size())-1){
			x=l[i][j];
			FOR(k,x+1,n){
				y=cnt[k+1]-(r[i][j]>k);
				if(y==0){
					if(F0[k]<f0[k]+1)F0[k]=f0[k]+1,G0[k]=0;
					if(F0[k]==f0[k]+1)check(G0[k]+=g0[k]);
					if(g1[k]&&F1[k]<f1[k]+1)F1[k]=f1[k]+1,G1[k]=0;
					if(F1[k]==f1[k]+1)check(G1[k]+=g1[k]);
				}
				else{
					if(F0[k]<f0[k]+2)F0[k]=f0[k]+2,G0[k]=0;
					if(F0[k]==f0[k]+2)check(G0[k]+=1ll*g0[k]*y%mod);
					if(g1[k]&&F1[k]<f1[k]+2)F1[k]=f1[k]+2,G1[k]=0;
					if(F1[k]==f1[k]+2)check(G1[k]+=1ll*g1[k]*y%mod);
				}
			}
			y=cnt[x+1]-(r[i][j]>x);
			if(y==0){
				if(F1[x]<f0[x]+1)F1[x]=f0[x]+1,G1[x]=0;
				if(F1[x]==f0[x]+1)check(G1[x]+=g0[x]);
			}
			else{
				if(F1[x]<f0[x]+2)F1[x]=f0[x]+2,G1[x]=0;
				if(F1[x]==f0[x]+2)check(G1[x]+=1ll*g0[x]*y%mod);
			}
		}
		FOR(k,1,n){
			y=cnt[k+1];
			if(y){
				if(F0[k]<f0[k]+1)F0[k]=f0[k]+1,G0[k]=0;
				if(F0[k]==f0[k]+1)check(G0[k]+=1ll*g0[k]*y%mod);
				if(F1[k]<f1[k]+1)F1[k]=f1[k]+1,G1[k]=0;
				if(F1[k]==f1[k]+1)check(G1[k]+=1ll*g1[k]*y%mod);
			}
		}
		y=cnt[1];
		if(y){
			if(F1[0]<f1[0]+1)F1[0]=f1[0]+1,G1[0]=0;
			if(F1[0]==f1[0]+1)check(G1[0]+=1ll*g1[0]*y%mod);
		}
		FOR(j,0,n){
			if(f0[j]<F0[j])f0[j]=F0[j],g0[j]=0;
			if(f0[j]==F0[j])check(g0[j]+=G0[j]);
			if(f1[j]<F1[j])f1[j]=F1[j],g1[j]=0;
			if(f1[j]==F1[j])check(g1[j]+=G1[j]);
		}
		y=0;
	}
	int maxn=0,ans=0;
	FOR(i,0,n){
		if(f1[i]>maxn)maxn=f1[i],ans=0;
		if(f1[i]==maxn)check(ans+=g1[i]);
	}
	cout<<maxn<<' '<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}