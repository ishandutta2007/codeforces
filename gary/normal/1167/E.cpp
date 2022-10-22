//* AuThOr GaRyMr *//
//solution by GaryMr
//first make the array [1,r]
//So easy!
//then iterate from r to n
//and iterate l from 1 to r
//if max[1,l]<=a[l+1].SEC&a[l+1]<=min[r+1,n]
//ans+=(l-1)*(n-r)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define read(a) scanf("%d",&a);
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
mp a[3000000+10];
int treen;
int tree[8*1000000][2];
//tree->0 min
//tree-> max
void build(int now,int l,int r){
	if(l==r-1){
		tree[now][0]=tree[now][1]=a[l].SEC;
		return ;
	}
	int mid=(l+r)>>1;
	build(now<<1,l,mid);
	build((now<<1)+1,mid,r);
	tree[now][0]=min(tree[now<<1][0],tree[(now<<1)+1][0]);
	tree[now][1]=max(tree[now<<1][1],tree[(now<<1)+1][1]);
}
int query(int now,int l,int r,int a,int b,int index){
	if(l>=b||r<=a){
		return (index)? -INF:INF; 
	}
	if(r<=b&&l>=a){
		return tree[now][index];
	}
	int mid=(l+r)>>1;
	return (index)? max(query(now<<1,l,mid,a,b,index),query((now<<1)+1,mid,r,a,b,index)):min(query(now<<1,l,mid,a,b,index),query((now<<1)+1,mid,r,a,b,index));
}
int max_query(int l,int r){
	if(r<=1){
		return -INF;
	}
	return query(1,1,treen+1,l,r,1);
}int n,x;
int min_query(int l,int r){
	if(l>n){
		return INF;
	}
	return query(1,1,treen+1,l,r,0);
}
int main(){
	int OK=1;
	read(n);
	read(x);
	treen=1<<int(ceil(log2(double(n)))); 
	a[0].FIR=a[0].SEC=0;
	rb(i,1,n){
		read(a[i].FIR);
		a[i].SEC=i;
		if(a[i].FIR<a[i-1].FIR){
			OK=0;
		}
	}
	if(OK){
		LL res=(LL)(x)*(LL)(x+1);
		res>>=1;
		printf("%I64d\n",res);
		return 0;
	}
	sort(a+1,a+1+n);
	build(1,1,treen+1);
	int tmp_minimum=INF;
	int ri,li;
	li=1;
	rl(i,n,1){
		if(a[i].SEC<=tmp_minimum){
			tmp_minimum=a[i].SEC;
			ri=i;
		}
		else{
			break;
		}
	}
	ri--;
	LL res=0;
//	cout<<ri<<endl;
//	ri++;
//	cout<<ri<<endl;
	a[n+1].FIR=x+1;
	rb(i,ri,n){
		while(li<i){
			if(max_query(1,li)<=a[li].SEC&&a[li].SEC<=min_query(i+1,n+1)){
				li++;
			}
			else{
				break;
			}
		}
//		cout<<li<<" "<<i<<endl;
//		cout<<"IS"<<a[li].FIR<<" "<< a[i+1].FIR<<" MINUS"<<a[i].FIR<<endl;
		res+=(LL)(a[li].FIR)*(LL)(a[i+1].FIR-a[i].FIR);
	}
	printf("%I64d\n",res);
	return 0;
}