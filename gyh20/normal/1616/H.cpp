#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline int High(re int x){
	re int s=0;
	while(x)x>>=1,++s;
	return s;
}
int pw[1500002],ch[5000002][2],sz1[5000002],sz2[5000002],tot;
inline void ins(re int x,re int o){
	re int nw=1;if(o)++sz1[nw];else ++sz2[nw];
	for(re int i=30;~i;--i){
		re int z=(x>>i)&1;
		if(!ch[nw][z])ch[nw][z]=++tot;
		nw=ch[nw][z];
		if(o)++sz1[nw];
		else ++sz2[nw];
	}
}
inline int solve(re int A,re int B,re int y,re int z){
	if(y==-1)return 1ll*(pw[sz1[A]]-1)*(pw[sz2[B]]-1)%M;
	if(!sz1[A]||!sz2[B])return 0;
	re int s=0;
	if(z&(1<<y)){
		add(s,1ll*(pw[sz1[ch[A][0]]]-1)*(pw[sz2[ch[B][0]]]-1)%M);
		add(s,1ll*(pw[sz1[ch[A][1]]]-1)*(pw[sz2[ch[B][1]]]-1)%M);
		re int X=solve(ch[A][0],ch[B][1],y-1,z),Y=solve(ch[A][1],ch[B][0],y-1,z);
		add(s,1ll*(X+1)*(Y+1)%M);add(s,M-1); 
		add(s,1ll*X*(pw[sz1[ch[A][1]]]-1+pw[sz2[ch[B][0]]]-1)%M);
		add(s,1ll*Y*(pw[sz1[ch[A][0]]]-1+pw[sz2[ch[B][1]]]-1)%M);
	}
	else add(s,solve(ch[A][0],ch[B][0],y-1,z)),add(s,solve(ch[A][1],ch[B][1],y-1,z));
	return s;
}
inline int solve(vector<int>A,re int x){
	re int y=High(x);
	vector<int>Q[32];
	for(re int i=0;i<A.size();++i)Q[High(A[i])].push_back(A[i]);
	re int s=0,sum=0;
	for(re int i=y+1;i<=30;++i)
		if(Q[i].size()){
			for(re int j=0;j<Q[i].size();++j)Q[i][j]^=(1<<i-1);
			add(s,solve(Q[i],x));
		}
	for(re int i=0;i<y;++i)sum+=Q[i].size();
	add(s,ksm(2,sum)-1),add(s,ksm(2,Q[y].size())-1);
	if(!y)return s;
	vector<int>X,Y;
	X=Q[y];
	for(re int i=0;i<y;++i)
		for(re int j=0;j<Q[i].size();++j)
			Y.push_back(Q[i][j]);
	for(re int i=0;i<X.size();++i)X[i]^=(1<<y-1);
	tot=1;
	for(re int i=0;i<X.size();++i)ins(X[i],0);
	for(re int i=0;i<Y.size();++i)ins(Y[i],1);
	add(s,solve(1,1,30,x^(1<<y-1)));
	for(re int i=0;i<=tot;++i)ch[i][0]=ch[i][1]=sz1[i]=sz2[i]=0;
	return s;
} 
int n,m;
int main(){
	n=read(),m=read();
	for(re int i=pw[0]=1;i<=n;++i)pw[i]=Mod(pw[i-1]+pw[i-1]);
	vector<int>A;
	for(re int i=1;i<=n;++i)A.push_back(read());
	printf("%d",solve(A ,m));
}