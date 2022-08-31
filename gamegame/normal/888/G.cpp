#include<iostream>
#include<cmath>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
int a[200001];
unordered_map<int,int>m[30];
int c[6000001][2];
int s=1;
void insert(int id){
	int ptr=1;
	for(int i=29; i>=0 ;i--){
		if(c[ptr][(a[id]&(1<<i))!=0]==0){
			s++;
			c[s][0]=c[s][1]=0;
			c[ptr][(a[id]&(1<<i))!=0]=s;
		}
		ptr=c[ptr][(a[id]&(1<<i))!=0];
	}
}
int match(int id){
	int ptr=1,val=0;
	for(int i=29; i>=0 ;i--){
		if(c[ptr][(a[id]&(1<<i))!=0]==0){
			val|=(1<<i);
			ptr=c[ptr][(a[id]&(1<<i))==0];
		}
		else ptr=c[ptr][(a[id]&(1<<i))!=0];
	}
	return val;
}
int find_min_xor(int l1,int r1,int l2,int r2){
	for(int i=l1; i<=r1 ;i++) insert(i);
	int ans=2e9;
	for(int i=l2; i<=r2 ;i++) ans=min(ans,match(i));
	s=1;
	c[1][0]=c[1][1]=0;
	return ans;
}
ll solve(int l,int r,int k){
	if(l==r) return 0;
	if(k<0) return 0;
	if((a[l]&(1<<k))==(a[r]&(1<<k))){
		return solve(l,r,k-1);
	}
	int ll=l,rr=r,mid;
	while(ll!=rr){
		mid=(ll+rr+1)/2;
		if(a[mid]&(1<<k)) rr=mid-1;
		else ll=mid;
	}
	mid=ll;
	int best=find_min_xor(l,mid,mid+1,r);
	return best+solve(l,mid,k-1)+solve(mid+1,r,k-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << solve(1,n,29) << endl;
}