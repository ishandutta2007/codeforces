#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node {
	int op,w,id;
	node(){}
	node(int OP,int W,int ID) {
		op=OP,w=W,id=ID;
	}
	int operator<(const node &a)const {
		return w==a.w?op<a.op:w<a.w;
	}
}p[N*2];
int l[N],r[N],d[8],f[1<<8],cnt[1<<8];
int main() {
	int n,k;
	scanf("%d%*d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",l+i,r+i);
		p[2*i-1]=node(1,l[i],i);
		p[2*i]=node(-1,r[i]+1,i);
	}
	for(int i=1;i<1<<k;i++)
		cnt[i]=cnt[i-(i&-i)]^1;
	sort(p+1,p+2*n+1);
	memset(f,0xc0,sizeof(f));
	f[0]=0;
	for(int i=1;i<=2*n;i++) {
		int id=-1,len=i==2*n?0:p[i+1].w-p[i].w;
		if(p[i].op==1) {
			for(int j=0;j<k&&id==-1;j++)
				if(!d[j])d[id=j]=p[i].id;
			if(id==-1)return -1;
			for(int j=(1<<k)-1;j>=0;j--) {
				if(j>>id&1)f[j]=f[j^1<<id]+cnt[j]*len;
				else f[j]=f[j]+cnt[j]*len;
			}
		} else {
			for(int j=0;j<k&&id==-1;j++)
				if(d[j]==p[i].id)d[id=j]=0;
			if(id==-1)return -1;
			for(int j=0;j<1<<k;j++)
				if(j>>id&1)f[j]=0xc0c0c0c0;
				else f[j]=max(f[j],f[j^1<<id])+cnt[j]*len;
		}
	}
	printf("%d\n",f[0]);
	return 0;
}