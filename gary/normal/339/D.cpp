#include<bits/stdc++.h>
using namespace std;
const int MAXN=1<<18;
int tree[4*MAXN];
int n,m;
int build(int k,int flag){
	if(k>n-1){
		return tree[k];
	}
	if(flag)return tree[k]=build(k*2,flag^1)^build(k*2+1,flag^1);
	else return tree[k]=build(k*2,flag^1)|build(k*2+1,flag^1);
}
void change(int k,int flag){
	if(k==1) return;
	if(flag)
	tree[k/2]=tree[(k/2)*2]|tree[(k/2)*2+1];
	else
	tree[k/2]=tree[(k/2)*2]^tree[(k/2)*2+1];
	change(k/2,flag^1);
}
int main(){
	scanf("%d %d",&n,&m);
	n=1<<n;
	for(int i=1;i<=n;i++) scanf("%d",&tree[n-1+i]);
	int Flag;
	if(int(log2(n))%2){
		Flag=0;
	}
	else{
		Flag=1;
	}
	build(1,Flag);
	while(m--){
		int p,b;
		scanf("%d %d",&p,&b);
		tree[n-1+p]=b;
		change(n-1+p,1);
		printf("%d\n",tree[1]);
	}
	return 0;
}