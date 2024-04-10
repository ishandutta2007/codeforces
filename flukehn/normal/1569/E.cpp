#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
const int N=1<<17|1;
int pa[333];
struct P{
	int v,p;
	bool operator<(const P& t)const{
		return v==t.v?p<t.p:v<t.v;
	}
};
P f[N];
int k,A,h;
int ans[333];
int m;

int a[333];
int work(int i,int pr,int fg){
	int s=1<<k-1;
	for(int j=1;j<=(1<<k-1);++j)a[j]=j+pr;
	int p=0;
	int w=0;
	while(s>1){
		int t=0;
		for(int j=1;j<=s;j+=2){
			if(i>>p&1){
				w=(w+1ll*a[j+1]*pa[ans[a[j+1]]=s+1])%mo;
				a[++t]=a[j];
			}
			else{
				w=(w+1ll*a[j]*pa[ans[a[j]]=s+1])%mo;
				a[++t]=a[j+1];
			}
			++p;
		}
		s=t;
	}
	assert(p==m);
	//cerr<<i<<" "<<pr<<" "<<w<<endl;
	//for(int j=1;j<=(1<<k-1);++j)cerr<<ans[j+pr]<<" \n"[j==(1<<k-1)];
	if(fg==0)ans[a[1]]=2,w=(w+1ll*a[1]*pa[2])%mo;
	else ans[a[1]]=1,w=(w+1ll*a[1]*pa[1])%mo;
	return w;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	//int T;cin>>T;
	while(cin>>k>>A>>h){
		pa[0]=1;
		for(int i=1;i<333;++i)pa[i]=1ll*pa[i-1]*A%mo;
		m=(1<<k-1)-1;
		//cerr<<"m="<<m<<endl;
		int flag=0;
		for(int i=0;i<(1<<m);++i){
			f[i]=(P){work(i,0,0),i};
		}
		sort(f,f+(1<<m));
		for(int i=0;i<(1<<m);++i){
			int w=work(i,(1<<k-1),1);
			w=(mo+h-w)%mo;
			auto j=lower_bound(f,f+(1<<m),(P){w,-1});
			if(j!=f+(1<<m) && j->v == w){
				flag=1;
				work(j->p,0,0);
				break;
			}
		}
		if(flag){
			for(int i=1;i<=(1<<k);++i)cout<<ans[i]<<" \n"[i==(1<<k)];
			continue;
		}

		for(int i=0;i<(1<<m);++i){
			f[i]=(P){work(i,(1<<k-1),0),i};
		}
		sort(f,f+(1<<m));
		for(int i=0;i<(1<<m);++i){
			int w=work(i,0,1);
			w=(mo+h-w)%mo;
			auto j=lower_bound(f,f+(1<<m),(P){w,-1});
			if(j!=f+(1<<m) && j->v == w){
				flag=1;
				work(j->p,1<<k-1,0);
				break;
			}
		}
		if(flag){
			for(int i=1;i<=(1<<k);++i)cout<<ans[i]<<" \n"[i==(1<<k)];
		}
		else{
			cout<<"-1\n";
		}
	}
}