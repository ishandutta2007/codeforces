#include<bits/stdc++.h>
using namespace std;
int n,q,mu[7005]={0,1},vst[7005],p[7005];
bitset<7005> t[7005],t2[7005],a[100005];
int main(){
	for(int i=2;i<=7000;i++){
		if(!vst[i])p[++p[0]]=i,mu[i]=-1;
		for(int j=1;j<=p[0];j++){
			if(i*p[j]>7000)break;
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
			mu[i*p[j]]=-mu[i];
		}
	}
	for(int i=1;i<=7000;i++)for(int j=i;j<=7000;j+=i)t2[j][i]=1,t[i][j]=(bool)mu[j/i];
	scanf("%d%d",&n,&q);
	while(q--){
		int o,x,y,z;
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)a[x]=t2[y];
		if(o==2)scanf("%d",&z),a[x]=a[y]^a[z];
		if(o==3)scanf("%d",&z),a[x]=a[y]&a[z];
		if(o==4)cout<<((a[x]&t[y]).count())%2;
	}
}