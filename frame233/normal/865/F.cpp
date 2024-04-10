#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
ll C[65][65],V[65];int r,c;char S[65];int A[65],B[65];
struct node{ll sum,cnt;inline bool operator < (const node &o)const{return sum<o.sum;}};
std::vector<node> vec[25];
int main(){
	for(int i=0;i<=60;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1]+C[i-1][j];
	scanf("%d%d%s",&r,&c,S);ll all=C[r+c][r]*C[r+c][r];
	int ca=0,cb=0;
	for(int i=0;i<2*(r+c);++i){
		if(S[i]=='A')++ca;else if(S[i]=='B')++cb;
		A[i]=ca,B[i]=cb;
	}
	for(int cb=0;cb<=r+c;++cb)for(int j=0;j<r;++j)V[cb]+=C[cb][j]*C[r+c-cb][r-j];
	for(int st=0;st<1<<(c+1);++st){
		int cura=0,curb=0;
		for(int i=0;i<c+1;++i)if(st>>i&1)++curb;else ++cura;
		int ca=r+c-cura,cb=r+c-curb;ll sum=0;
		for(int i=0;i<c+1;++i){
			if(!(st>>i&1))++ca,sum+=C[ca-1][r-1]*V[cb];
			else ++cb;
		}
		int coef=1;for(int i=0;i<c+1;++i)coef&=S[r-1+r+c+i]!=((st>>i&1)^1)+'A';
		vec[cura].pb({sum,coef});
	}
	for(int i=0;i<=c+1;++i){
		std::sort(vec[i].begin(),vec[i].end());std::vector<node> tmp;
		for(const auto &it:vec[i]){
			if(tmp.empty()||it.sum!=tmp.back().sum)tmp.pb(it);
			else tmp.back().cnt+=it.cnt;
		}
		vec[i]=tmp;
	}
	ll mn=1e18,res=0;
	for(int st=0;st<1<<(c+1);++st){
		int ca=r-1,cb=r-1;ll sum=0;
		for(int i=0;i<c+1;++i){
			if(!(st>>i&1))++ca,sum+=C[ca-1][r-1]*V[cb];
			else ++cb;
		}
		int to=r+c-ca;ll coef=1;
		int p=0;while(p<c&&(st>>(p+1)&1)==(st>>p&1))++p;
		ca=r-1,cb=r-1;for(int i=0;i<=p;++i)if(st>>i&1)++cb;else ++ca;
		for(int i=p+1;i<c+1;++i)coef&=S[r+r-2+i]!=((st>>i&1)^1)+'A';
		ca-=A[r+r-2+p],cb-=B[r+r-2+p];if(ca<0||cb<0)coef=0;else coef*=C[ca+cb][ca];
		auto it=std::upper_bound(vec[to].begin(),vec[to].end(),(node){all/2-sum,0});
		if(it!=vec[to].end()){
			ll tmp=std::max(sum+it->sum,all-(sum+it->sum));
			if(tmp<mn)mn=tmp,res=0;
			if(tmp==mn)res+=coef*it->cnt;
		}
		if(it!=vec[to].begin()){
			--it;ll tmp=std::max(sum+it->sum,all-(sum+it->sum));
			if(tmp<mn)mn=tmp,res=0;
			if(tmp==mn)res+=coef*it->cnt;
		}
	}
	printf("%lld\n",res);
	return 0;
}