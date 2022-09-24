#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[270000],rev[20],l[20],r[20],len[20];
ll c[270000];
void U(int x,int k){
	x++;
	while(x<=(1<<n))c[x]+=k,x+=x&-x;
}
ll Q(int x){
	x++;
	ll r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
ll Query(int x){
	ll ret=0;
	int cc=0;
	if(x<0)return 0;
	for(int i=n,nl=0;i>=0;i--)if((x+1)&(1<<i))l[++cc]=nl,r[cc]=nl+(1<<i)-1,len[cc]=i,nl+=(1<<i);
	for(int i=1;i<=n;i++){
		if(!rev[i])continue;
		for(int j=1;j<=cc;j++){
			if(len[j]<i){
				int L=l[j]%(1<<i),R=r[j]%(1<<i),FI=((l[j]>>i)<<i);
				l[j]=(1<<i)-R-1+FI;r[j]=(1<<i)-L-1+FI;
			}
		}
	}
	for(int i=1;i<=cc;i++)ret+=Q(r[i])-Q(l[i]-1);
	return ret;
}
int Find(int x){
	for(int i=1;i<=n;i++){
		if(!rev[i])continue;
		int FI=((x>>i)<<i);
		x=(1<<i)-x%(1<<i)-1+FI;
	}
	return x;
}
int main() {
	cin>>n>>m;
	for(int i=0;i<(1<<n);i++)scanf("%d",&a[i]),U(i,a[i]);
	for(int i=1,opt,x,y;i<=m;i++){
		scanf("%d%d",&opt,&x);
		if(opt==1)x--,scanf("%d",&y),x=Find(x),U(x,y-a[x]),a[x]=y;
		if(opt==2)rev[x]^=1;
		if(opt==3)rev[x]^=1,rev[x+1]^=1;
		if(opt==4)x--,scanf("%d",&y),y--,printf("%lld\n",Query(y)-Query(x-1));
		//for(int i=1;i<=(1<<n);i++)printf("%lld ",Query(i-1)-Query(i-2)); 
		//puts("");
	}
	return 0;
}