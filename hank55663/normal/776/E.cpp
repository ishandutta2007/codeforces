#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 500005
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int isPrime[1000005];
vector<int> prime;
void find(){
	for(int i=0;i<1000005;i++)
	isPrime[i]=1;
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i<1000005;i++){
		if(isPrime[i]){
			prime.pb(i);
			for(int j=i*2;j<1000005;j+=i)
			isPrime[j]=0;
		}
	}
}
LL count(LL n,vector<LL> v,int i,int use,LL sum){
	//printf("%d %I64d\n",i,sum);
	if(i>=v.size()){
		if(use%2==0)
		return n/sum-1;
		else
		return -n/sum+1;
	}
	LL res=count(n,v,i+1,use,sum)+count(n,v,i+1,use+1,sum*v[i]);
	return res;
}
LL f(LL n,LL k){
	if(k==0)
	return n;
	if(k%2==0)
	return f(n,k-1);
	//printf("%I64d %I64d\n",n,k);
//	system("PAUSE");
	if(n==1)
	return 1;
	LL sum=n-1;
	LL NN=n;
	vector<LL> v;
	for(int i=0;i<prime.size()&&prime[i]<NN;i++){
		if(NN%prime[i]==0){
			v.pb(prime[i]);
			while(NN%prime[i]==0)
			NN/=prime[i];
			//printf("%d %I64d\n",prime[i],NN);
		}
	}
//	printf("\n");
	if(NN!=1&&NN!=n)
	v.pb(NN);
	sum=count(n,v,0,0,1);
	return f(sum,k-1);
}
//12332784660
int main(){
	LL n,k;
	find();
	scanf("%I64d %I64d",&n,&k);
	printf("%I64d\n",f(n,k)%mod);
}