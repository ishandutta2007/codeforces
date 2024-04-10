
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=300;
int n,m,c[400005],X[400005],Y[400005],lst[400005];
struct BIT{
	int c[405],N;
	void U(int x,int y,int z){for(int i=x;i<=y;i++)c[i]+=z;}
	int Q(int x){return c[x];}
}b[405];
void Add(int x,int id){
	lst[x]=id;
	if(X[x]+Y[x]>B){
		int u=id;
		while(u<=m)c[u+X[x]]++,c[min(m+1,u+X[x]+Y[x])]--,u+=X[x]+Y[x];
	}
	else {
		int t=(X[x]+id)%(X[x]+Y[x]),tt=(id-1)%(X[x]+Y[x]);
		if(t<=tt)b[X[x]+Y[x]].U(t,tt,1);
		else b[X[x]+Y[x]].U(t,X[x]+Y[x]-1,1),b[X[x]+Y[x]].U(0,tt,1);
	}
}
void Del(int x,int curid){
	if(X[x]+Y[x]>B){
		int u=lst[x];
		while(u<=m){
			int l=u+X[x],r=min(m+1,u+X[x]+Y[x])-1;
			if(r<curid){
				u+=X[x]+Y[x];
				continue;
			}
			if(l<=curid&&r>=curid)c[curid]--,c[r+1]++,u+=X[x]+Y[x];
			else c[l]--,c[r+1]++,u+=X[x]+Y[x];
		}
	}
	else {
		int id=lst[x];
		int t=(X[x]+id)%(X[x]+Y[x]),tt=(id-1)%(X[x]+Y[x]);
		if(t<=tt)b[X[x]+Y[x]].U(t,tt,-1);
		else b[X[x]+Y[x]].U(t,X[x]+Y[x]-1,-1),b[X[x]+Y[x]].U(0,tt,-1);
	}
	lst[x]=0;
}
int p1=2000000;
char buf[2000005];
int gc(){
	if(p1>=2000000)fread(buf,1,2000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x;
}
int main(){
	for(int i=1;i<=B;i++)b[i].N=i;
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)X[i]=rd(),Y[i]=rd(),X[i]=min(X[i],m),Y[i]=min(Y[i],m);
	for(int i=1,op,x;i<=m;i++){
		op=rd(),x=rd();
		if(lst[x])Del(x,i);
		else Add(x,i);
		c[i]+=c[i-1];
		int ans=c[i];
		for(int j=1;j<=B;j++)ans+=b[j].Q(i%j);
		cout<<ans<<'\n';
	}
}