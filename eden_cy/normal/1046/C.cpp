#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define DOR(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
#define ll long long
#define M 200005
using namespace std;

int n,m;
int A[M];
int B[M];

bool check(int x){
	int tot=A[m]+B[1];
	int now=n;
	int flag=1;
	FOR(i,x,n){
		if(i==m)continue;
		int res=A[i]+B[now];
		if(res>tot)flag=0;
		now--;
	}
	return flag;
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n)scanf("%d",&A[i]);
	FOR(i,1,n)scanf("%d",&B[i]);
	int L=1,R=n,res=n;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid))res=mid,R=mid-1;
		else L=mid+1;
	}
	printf("%d\n",res);
	return 0;
}