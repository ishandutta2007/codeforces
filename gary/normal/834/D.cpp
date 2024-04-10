/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	c[i]
	
	long long
	
	dp
	
	 >=0
	
	dpg
	:find max(find(k*2,a,b,l,mid,id),find(k*2+1,a,b,mid,r,id))+ever[id][k]+ever[id][k] 
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	ceil(log2(double(n)))
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,k,a[35001],dp[35001][55];
int tree[55][176000],ever[55][176000];
int put(int k,int a,int b,int l,int r,int id,int val){
//	cout<<l<<" "<<r<<" "<<val<<endl;
	if(r<=a||l>=b){
		return tree[id][k]+ever[id][k];
	}
	if(r<=b&&l>=a){
//		cout<<l<<" "<<r<<"FROM"<<ever[id][k]<<"ADD TO>"<<ever[id][k]+val<<endl;
		ever[id][k]+=val;
		return tree[id][k]+ever[id][k];
	}
	int mid=(l+r)>>1;
	return (tree[id][k]=max(put(k*2,a,b,l,mid,id,val),put(k*2+1,a,b,mid,r,id,val)))+ever[id][k];
}
int find(int k,int a,int b,int l,int r,int id){
//	cout<<"Start Finding"<<l<<" "<<r<<endl;
	if(r<=a||l>=b) return 0;
	if(r<=b&&l>=a){
	return ever[id][k]+tree[id][k];
	} 
	int mid=(l+r)>>1;
	return max(find(k*2,a,b,l,mid,id),find(k*2+1,a,b,mid,r,id))+ever[id][k];
}
int main(){
	scanf("%d %d",&n,&k);
	rb(i,0,n-1) scanf("%d",&a[i]);
	int pre[35001],last[35001];
	memset(last,0,sizeof(last));
	map<int,int> m;
	int tohere[35001]={0};
	rb(i,0,n-1){
		tohere[i]=tohere[max(0,i-1)];
		if(!m[a[i]]){
			m[a[i]]=1;
			tohere[i]++;
		}
//		cout<<tohere[i]<<" ";
		pre[i]=last[a[i]];
		last[a[i]]=i;
	}	
	int startn=n;//cout<<n<<endl;
	n=1<<int(ceil(log2(double(n))));//cout<<n<<endl;
	rb(i,0,startn-1){
		rb(j,1,k){
			put(1,pre[i],i,0,n,j-1,1);
			if(i==0){
				dp[i][j]=1;
			}
			else{
				if(j==1) dp[i][j]=tohere[i];		
			else dp[i][j]=find(1,0,i,0,n,j-1);
			}
			put(1,i,i+1,0,n,j,dp[i][j]);
		}
	}
	
	printf("%d\n",dp[startn-1][k]);
	return 0;
}