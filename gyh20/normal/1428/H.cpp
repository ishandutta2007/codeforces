#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,lst,num,ans[10002],typ,tot;
char v[10002];
vector<int>tmp;
inline int ask(re int x,re int y){
	++tot,assert(tot<=15000);
	printf("? %d %d\n",x,y);fflush(stdout);
	re int z=read();
	swap(z,lst);
	return lst-z;
}
inline int solve(vector<int>&V,re int o){
	if(V.size()==1){
		typ=o;
		return V[0];
	}
	vector<int>L,R;
	re int mid=V.size()>>1;
	for(re int i=0;i<mid;++i)L.push_back(V[i]);
	for(re int i=mid;i<V.size();++i)R.push_back(V[i]);
	if(o==0){
		for(re int i=0;i<L.size();++i)ask(L[i],-1);
		re int o=ask(0,-1);ask(0,1);
		if(o<0)return solve(R,0);
		return solve(L,1);
	}
	else{
		for(re int i=0;i<L.size();++i)ask(L[i],1);
		re int o=ask(0,-1);ask(0,1);
		if(o<0)return solve(L,0);
		return solve(R,1);
	}
} 
int main(){
	n=read(),m=read(),v[0]=1,srand(time(0));
	ask(0,1),ask(0,-1),num=1;
	re int ll=0;
	for(re int i=1;i<=n*m;++i){
		int o=ask(0,1);
		if(ll==1&&o!=1){
			ask(0,-1),ask(0,-1);
			break;
		}
		ll=o;
	}ask(0,-1);
	for(re int i=1;i<=n*m;++i){
		int o=ask(0,1);
		if(o==1&&num<n){
			re int oo=ask(0,1);
			ask(0,-1);
			if(oo!=1){
				tmp.clear();
				for(re int j=0;j<n;++j)if(!v[j])tmp.push_back(j);
				re int pos=solve(tmp,0);++num;
				for(re int i=typ;i<m+1;++i)ask(pos,-1);
				ans[pos]=(i-m-1+n*m)%(n*m),v[pos]=1; 
				--i,ask(0,-1);
			}
		}
	}printf("! ");
	for(re int i=1;i<n;++i)printf("%d ",ans[i]);fflush(stdout);
}