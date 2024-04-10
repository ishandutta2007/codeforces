#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,C,mu[1000002],f[1000002],g[1000002],h[1000002],V[1000002],p[1000002],B[32],RV[32],A[102];
bitset<32>U[32];
vector<int>tmp,G[1000002],ans;
inline bool cmp(re int x,re int y){return G[x].size()>G[y].size();}
inline void Ins(re int x){
	bitset<32>tmp;tmp.reset();re int oo=x;
	for(re int i=30;~i;--i)
		if(x&(1<<i)){
			if(B[i]){
				tmp^=U[i];
				x^=B[i];
			}
			else{
				RV[i]=oo;
				tmp[i]=1;
				U[i]=tmp;
				B[i]=x;
				return;
			}
		}
}
inline void clr(){
	memset(B,0,sizeof(B)),memset(RV,0,sizeof(RV));
	for(re int i=0;i<=30;++i)U[i].reset();
}
map<int,vector<int> >Ans[502];
bitset<1000002>W[502];
inline int ask(re int x){
	re int s=0;
	for(re int i=1;i<=n;++i)if(__gcd(A[i],x)==1)s^=A[i];
	return s;
}
int main(){
	C=read(),n=read(),mu[1]=1,tmp.push_back(1);
//	for(re int i=1;i<=n;++i)A[i]=read();
	for(re int i=1;i<=C;++i)V[i]=1; 
	for(re int i=2;i<=C;++i){
		--mu[i];
		for(re int j=i+i;j<=C;j+=i)mu[j]-=mu[i];
		if(mu[i])tmp.push_back(i);
	}
	printf("%u ",tmp.size());
	for(auto z:tmp)printf("%d ",z);puts(""),fflush(stdout);
	for(re int i=0;i<tmp.size();++i)f[tmp[i]]=read();
	for(re int i=1;i<=C;++i)if(mu[i]){
		g[i]^=f[i];
		for(re int j=i+i;j<=C;j+=i)g[j]^=g[i];
	}
	for(re int i=1;i<=C;++i)for(re int j=i;j<=C;j+=i)if(mu[j])h[i]^=g[j];
	for(re int i=2;i<=C;++i)if(V[i]==1)for(re int j=i;j<=C;j+=i)V[j]*=i;
	for(re int i=1;i<=C;++i)G[V[i]].push_back(i),p[i]=i;
	sort(p+1,p+C+1,cmp);
	for(re int i=501;i<=C;++i)if(G[p[i]].size()){
		clr();
		for(auto z:G[p[i]])Ins(z);
		re int xx=h[p[i]];bitset<32>tmp;tmp.reset();
		for(re int j=30;~j;--j)if(xx&(1<<j))xx^=B[j],tmp^=U[j];
		for(re int j=30;~j;--j)if(tmp[j])ans.push_back(RV[j]);
	}
	re int dlt=n-ans.size();
	W[0][0]=1;
	for(re int i=1;i<=min(500,C);++i)
		if(G[p[i]].size()){
			clr();
			for(auto z:G[p[i]])Ins(z);
			for(re int j=0;j<=60;++j){
				random_shuffle(G[p[i]].begin(),G[p[i]].end());
				vector<int>T;
				re int ss=h[p[i]];
				for(re int k=0;k<min((int)G[p[i]].size(),j);++k)ss^=G[p[i]][k],T.push_back(G[p[i]][k]);
				bitset<32>tmp;tmp.reset();
				for(re int j=30;~j;--j)if(ss&(1<<j))ss^=B[j],tmp^=U[j];
				if(ss)continue;
				for(re int j=30;~j;--j)if(tmp[j])T.push_back(RV[j]);
				sort(T.begin(),T.end());
				vector<int>nt;
				for(re int i=0;i<T.size();++i){
					re bool ia=1;
					if(i)ia&=T[i]!=T[i-1];
					if(i+1!=T.size())ia&=T[i]!=T[i+1];
					if(ia)nt.push_back(T[i]);
				}
				T=nt;
				re int sss=0;
				for(auto z:T)sss^=z;
				assert(sss==h[p[i]]);
				if(!Ans[i].count(T.size())){
					Ans[i][T.size()]=T;
					W[i]|=W[i-1]<<T.size();
				}
			}
			for(re int j=1;j<=10;++j){
				random_shuffle(G[p[i]].begin(),G[p[i]].end());
				vector<int>T;
				re int ss=h[p[i]];
				for(re int k=0;k<min((int)G[p[i]].size(),j);++k)ss^=G[p[i]][k],T.push_back(G[p[i]][k]);
				bitset<32>tmp;tmp.reset();
				for(re int j=30;~j;--j)if(ss&(1<<j))ss^=B[j],tmp^=U[j];
				if(ss)continue;
				for(re int j=30;~j;--j)if(tmp[j])T.push_back(RV[j]);
				sort(T.begin(),T.end());
				vector<int>nt;
				for(re int i=0;i<T.size();++i){
					re bool ia=1;
					if(i)ia&=T[i]!=T[i-1];
					if(i+1!=T.size())ia&=T[i]!=T[i+1];
					if(ia)nt.push_back(T[i]);
				}
				T=nt;
				re int sss=0;
				for(auto z:T)sss^=z;
				assert(sss==h[p[i]]);
				if(!Ans[i].count(T.size())){
					Ans[i][T.size()]=T;
					W[i]|=W[i-1]<<T.size();
				}
			}
			for(re int j=1;j<=10;++j){
				random_shuffle(G[p[i]].begin(),G[p[i]].end());
				vector<int>T;
				re int ss=h[p[i]];
				for(re int k=0;k<min((int)G[p[i]].size(),j);++k)ss^=G[p[i]][k],T.push_back(G[p[i]][k]);
				bitset<32>tmp;tmp.reset();
				for(re int j=30;~j;--j)if(ss&(1<<j))ss^=B[j],tmp^=U[j];
				if(ss)continue;
				for(re int j=30;~j;--j)if(tmp[j])T.push_back(RV[j]);
				sort(T.begin(),T.end());
				vector<int>nt;
				for(re int i=0;i<T.size();++i){
					re bool ia=1;
					if(i)ia&=T[i]!=T[i-1];
					if(i+1!=T.size())ia&=T[i]!=T[i+1];
					if(ia)nt.push_back(T[i]);
				}
				T=nt;
				re int sss=0;
				for(auto z:T)sss^=z;
				assert(sss==h[p[i]]);
				if(!Ans[i].count(T.size())){
					Ans[i][T.size()]=T;
					W[i]|=W[i-1]<<T.size();
				}
			}
		}
	for(re int i=min(500,C);i;--i){
		re bool ia=1;
		for(auto z:Ans[i]){
			if(W[i-1][n-(int)ans.size()-z.first]){
				for(auto oo:z.second)ans.push_back(oo);
				ia=0;
				break;
			}
		}//assert(!ia);
	}
	assert(ans.size()==n);
	for(auto z:ans)printf("%d ",z);
	
}