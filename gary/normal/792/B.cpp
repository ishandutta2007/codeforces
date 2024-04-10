//* AuThOr GaRyMr *//
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
int pre[102],aft[102];
int a[101];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	rb(i,1,k) scanf("%d",&a[i]);
	int rest=n;
	rb(i,1,n){
		aft[i]=i+1;
		pre[i]=i-1;
	}
	aft[n]=1;
	pre[1]=n;
	int now=1;
	rb(i,1,k){
		int move=a[i]%rest;
		int tmp_now=now;
		rb(i,1,move){
			tmp_now=aft[tmp_now];
		}
		printf("%d ",tmp_now);
		now=aft[tmp_now];
		rest--;
		pre[aft[tmp_now]]=pre[tmp_now];
		aft[pre[tmp_now]]=aft[tmp_now];
	}
	return 0;
}