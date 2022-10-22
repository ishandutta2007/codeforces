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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,q;
int a[1000010];
int l=0,r=-1;
LL each[300000+10];
int firn[300000+10][2];
void solve(LL now){
	if(now<=n){
//		cout<<"*"<<now<<endl;
		printf("%d %d\n",firn[now][0],firn[now][1]);
	}
	else{
		now-=n;
		now%=(n-1);
		if(now==0) now=n-1;
		printf("%d %d\n",a[l],a[l+now]);
	}
}
int main(){
	scanf("%d %d",&n,&q);
	rb(i,1,n){
		int num;
		scanf("%d",&num);
		a[++r]=num;
	}
	rb(i,1,q){
		scanf("%I64d",&each[i]);
	}
	rb(i,1,n){
		int A,B;
		A=a[l++];
		B=a[l++];
		firn[i][0]=A;
		firn[i][1]=B;
		a[--l]=max(A,B);
		a[++r]=min(A,B);
	}
	rb(i,1,q){
		solve(each[i]);
	}
	return 0;
}