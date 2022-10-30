#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=100015;
typedef std::pair<int,int> pi;
char s[N];std::vector<pi> e[N];
bool inq[N];int _q[N*10],_l,_r;
int f[8][N],g[8][8],c[8][1<<8];
int main(){
	int n;scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i)e[s[i]-'a'+n+1].pb({i,0}),e[i].pb({s[i]-'a'+n+1,1});
	for(int i=1;i<n;++i)e[i].pb({i+1,1}),e[i+1].pb({i,1});
	memset(f,63,sizeof(f)),memset(g,63,sizeof(g));
	for(int i=0;i<8;++i){
		_q[_l=_r=1]=i+n+1;f[i][i+n+1]=0;
		while(_l!=_r+1){
			int x=_q[_l++];inq[x]=false;
			for(auto [v,w]:e[x])if(f[i][v]>f[i][x]+w){
				f[i][v]=f[i][x]+w;
				if(!inq[v])_q[++_r]=v,inq[v]=true;
			}
		}
		for(int j=1;j<=n;++j)chmin(g[i][s[j]-97],f[i][j]);
	}
	int ans=-1;long long res=0;
	for(int i=1;i<=n;++i){
		for(int j=std::max(1,i-16);j<i;++j){
			int w=i-j;for(int k=0;k<8;++k)chmin(w,f[k][i]+f[k][j]+1);
			if(w>ans)ans=w,res=1;else if(w==ans)++res;
		}
		if(i-17>0){
			int st=0;for(int j=0;j<8;++j)st|=(f[j][i-17]-g[j][s[i-17]-'a'])<<j;
			++c[s[i-17]-'a'][st];
		}
		for(int j=0;j<8;++j){
			for(int k=0;k<1<<8;++k)if(c[j][k]){
				int w=1e9;for(int t=0;t<8;++t)chmin(w,f[t][i]+g[t][j]+(k>>t&1)+1);
				if(w>ans)ans=w,res=c[j][k];else if(w==ans)res+=c[j][k];
			}
		}
	}
	printf("%d %lld\n",ans,res);
	return 0;
}