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
int a[200000+10];
mp turn[200000+10];
int Time [200000+10];
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
		turn[i]=II(a[i],0);
	}
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		int ty;
		scanf("%d",&ty);
		if(ty==1)
		{
			int p,x;
			scanf("%d %d",&p,&x);
			turn[p]=II(x,i);
		}
		else{
			int x;
			scanf("%d",&x);
			Time[i]=x;
		}
	}
	rl(i,q,0){
		Time[i]=max(Time[i+1],Time[i]);
	}
	rb(i,1,n){
		cout<<max(turn[i].FIR,Time[turn[i].SEC])<<" ";
	}
	return 0;
}