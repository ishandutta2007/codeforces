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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
pair<mp,int> a[300000+10];
int n; 
mp mini[300000+10];
bool cmp(pair<mp,int> A,pair<mp,int> B){
	if(A.FIR.FIR!=B.FIR.FIR) return A<B;
	return A.FIR.SEC>B.FIR.SEC;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		int li,ri;
		scanf("%d %d",&li,&ri);
		a[i]=II(II(li,ri),i);
	}
	sort(a+1,a+1+n,cmp);
	mini[n+1]=II(INF,INF); 
	rl(i,n,1){
		mini[i]=min(mini[i+1],II(a[i].FIR.SEC,a[i].SEC));
	}
	rb(i,1,n-1){
		if(mini[i+1].FIR<=a[i].FIR.SEC){
			printf("%d %d\n",mini[i+1].SEC,a[i].SEC);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
}