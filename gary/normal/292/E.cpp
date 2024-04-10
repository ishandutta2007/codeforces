/*
	/\/\/\/\/\Author GaryMr/\/\/\/\/\
	
	long long
	
	dp
	
	 >=0
	
	dpg
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 ! Process N: n=(1<<int(ceil(double(log2(double(n))))));
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;
#define debug(a) cout<<#a<<":"<<a<<" "; 
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[100001],b[100001],color[1000001],n,m/*1<=n,m<=1e5*/,y[100001],x[100001];
int ask(int k,int fa,int fb,int l,int r){
//	 debug(fa);debug(fb);debug(l);debug(r);cout<<endl;
	if(color[k]) {
//		cout<<"COLOR:"<<color[k]<<endl;
		return a[fa-y[color[k]]+x[color[k]]];
	}
	if(l==r-1) return b[l];
	int mid=(l+r)>>1;
	if(l<=fa&&mid>=fb) return ask(k<<1,fa,fb,l,mid);
	else return ask((k<<1)+1,fa,fb,mid,r);
}
void change(int k,int fa,int fb,int l,int r,int num){
//	debug(num);debug(fa);debug(fb);debug(l);debug(r);cout<<endl;
	if(l>=fb||r<=fa) return; 
	if(r<=fb&&l>=fa){
//		cout<<"Colored! ";    debug(fa);debug(fb);debug(l);debug(r);cout<<endl;
		color[k]=num;
		return;
	} 
	if(color[k]){
		int ThisColor=color[k];
		color[k]=0;
		if(l<fa){
			change(1,l,fa,1,n+1,ThisColor);
		}
		if(r>fb){
			change(1,fb,r,1,n+1,ThisColor);
		}
		
	} 
	int mid=(l+r)>>1;
	change(k*2,fa,fb,l,mid,num);
	change(k*2+1,fa,fb,mid,r,num);
}
int main(){
//	freopen("out.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	n=(1<<int(ceil(double(log2(double(n))))));
	for(int i=1;i<=m;i++){
		int type;
		scanf("%d",&type);
		if(type==2){
			int num;
			scanf("%d",&num);
			printf("%d\n",ask(1,num,num+1,1,n+1));
		}
		else{
			int k;
			scanf("%d %d %d",&x[i],&y[i],&k);
			change(1,y[i],y[i]+k,1,n+1,i);
		}
	}
	return 0;
}