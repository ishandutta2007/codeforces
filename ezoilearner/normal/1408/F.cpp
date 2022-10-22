#include<bits/stdc++.h>
using namespace std;
int n;
#define Maxn 500010
int A[Maxn],B[Maxn],cnt;
void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);
	solve(mid+1,r);
	for(int i=l;i<=mid;++i){
		cnt++;
		A[cnt]=i;
		B[cnt]=i+mid-l+1;
	}
} 
int main(){
	cin>>n;
	int bit=1;
	while(bit*2<=n)bit<<=1;
	solve(1,bit);
	if(bit<n)solve(n-bit+1,n);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)cout<<A[i]<<" "<<B[i]<<endl;
	return 0;
}