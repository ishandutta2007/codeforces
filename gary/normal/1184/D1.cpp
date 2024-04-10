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
int n,k,m,t;
void solve(){
	int ty,i;
	scanf("%d %d",&ty,&i);
	if(ty){
		if(i<=k) k++;
		n++;
	}
	else{
		if(i<k){
			n-=i;
			k-=i;
		}
		else{
			n-=n-i;
		}
	}
	printf("%d %d\n",n,k);
}
int main(){
	cin>>n>>k>>m>>t;
	while(t--){
		solve();
	}
	return 0;
}