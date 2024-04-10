#include<bits/stdc++.h>
using namespace std;
long long n,m,tree[10000001],startn,ever[10000001]={0};
long long find(int k,int a,int b,int l,int r){
	if(l>=b||r<=a) return 1e15;
	if(r<=b&&l>=a) return tree[k]+ever[k];
	int mid=(l+r)>>1;
	return min(find(k<<1,a,b,l,mid),find((k<<1)+1,a,b,mid,r))+ever[k];
}
long long put(int k,int a,int b,int l,int r,int x){
	if(l>=b||r<=a) return tree[k]+ever[k];
	if(l>=a&&r<=b){
		ever[k]+=x;
		return tree[k]+ever[k];
	}
	int mid=(l+r)>>1;
	tree[k]=min(put(k*2,a,b,l,mid,x),put(k*2+1,a,b,mid,r,x));
	return tree[k]+ever[k];
}
int main(){
	scanf("%I64d",&n);
	startn=n;	
	n=1<<int(ceil(log2(double(n))));
	for(int i=0;i<startn;i++){
		long long num;
		scanf("%I64d",&num);
		put(1,i,i+1,0,n,num);
	}
	scanf("%I64d",&m);
	getchar();
	for(int i=1;i<=m;i++){
		char c;
		int num[4]={0};
		int stage=1;
		bool flag=0;
		while(c=getchar()){
			if(c=='-'){
				flag=1;
				continue;
			}
			if(c=='\n') break;
			if(c==' '){
				if(flag){
					num[stage]=-num[stage];
				}
				flag=0;
				stage++;
			 continue;
			}
			num[stage]*=10;
			num[stage]+=c^48;
		}
		if(flag){
			num[stage]=-num[stage];
		}
		if(stage==2){
			if(num[1]<=num[2]){
				printf("%I64d\n",find(1,num[1],num[2]+1,0,n));
			}
			else{
				printf("%I64d\n",min(find(1,0,num[2]+1,0,n),find(1,num[1],startn,0,n)));
			}
		}
		else{
			if(num[1]<=num[2]){
				put(1,num[1],num[2]+1,0,n,num[3]);
			}
			else{
				put(1,0,num[2]+1,0,n,num[3]);
				put(1,num[1],startn,0,n,num[3]);
			}
		}
	}
	return 0;
}