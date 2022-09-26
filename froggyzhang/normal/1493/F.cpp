#include<bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
namespace Grader{
	int a[N][N];
	void init(){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=read();
			}
		}
	}
	int query(int h,int w,int i1,int j1,int i2,int j2){
		static int vis[N][N];
		for(int x=0;x<h;++x){
			for(int y=0;y<w;++y){
				vis[i1+x][j1+y]=1;
			}
		}
		for(int x=0;x<h;++x){
			for(int y=0;y<w;++y){
				assert(!vis[i2+x][j2+y]);
			}
		}
		for(int x=0;x<h;++x){
			for(int y=0;y<w;++y){
				vis[i1+x][j1+y]=0;
			}
		}
		for(int x=0;x<h;++x){
			for(int y=0;y<w;++y){
				if(a[i1+x][j1+y]^a[i2+x][j2+y])return 0;
			}
		}
		return 1;
	}
	int calc(){
		int tot=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(n%i==0&&m%j==0){
					bool ok=true;
					for(int x=1;x<=n&&ok;x+=i){
						for(int y=1;y<=m;y+=j){
							if(x==1&&y==1)continue;
							if(!query(i,j,1,1,x,y)){
								ok=false;break;;
							}
						}
					}
					tot+=ok;
				}
			}
		}
		return tot;
	}
};
int ask(int h,int w,int i1,int j1,int i2,int j2){
	printf("? %d %d %d %d %d %d\n",h,w,i1,j1,i2,j2);
	fflush(stdout);
//	int tmp=Grader::query(h,w,i1,j1,i2,j2);
//	cerr<<tmp<<endl;
//	return tmp;
	return read();
}
void report(int ans){
	printf("! %d\n",ans);
	fflush(stdout);
}
int Solve(int x,int flag){
	vector<pair<int,int> > fac;
	int tp=x;
	for(int i=2;i<=tp;++i){
		if(tp%i==0){
			int cnt=0;
			while(tp%i==0)tp/=i,++cnt;
			fac.emplace_back(i,cnt);
		}
	}
	int ans=1;
	for(auto [t,c]:fac){
		int k=x;
		int zyk=1;
		while(c--){
			int now=k/t;
			bool ok=true;
			while((now<<1)<k){
				if(flag?(!ask(n,now,1,1,1,now+1)):(!ask(now,m,1,1,now+1,1))){
					ok=false;break;
				}
				now<<=1;
			}
			if(ok)if(flag?(!ask(n,k-now,1,1,1,now+1)):(!ask(k-now,m,1,1,now+1,1)))ok=false;
			if(!ok)break;	
			k/=t;
			++zyk;
		}
		ans*=zyk;
	}
	return ans;
}
int main(){
	n=read(),m=read();
	
//	Grader::init();
	
	report(Solve(n,0)*Solve(m,1));
	
//	cerr<<" ans: "<<Grader::calc()<<endl;
	return 0;
}