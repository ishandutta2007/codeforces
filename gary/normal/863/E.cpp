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
mp a[200000+10]; 
map<int,int> have;
int sum[800000+10];
int st[800000+10][50];
int main(){ 
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d %d",&a[i].FIR,&a[i].SEC);
		have[a[i].FIR-1]=have[a[i].SEC]=true; 
	}
	map<int,int> :: IT ite;
	int tot=0;
	for(ite=have.begin();ite!=have.end();ite++)
	{
//		cout<<ite->FIR<<endl;
//		cout<<ite->FIR<<" "<<1+tot<<endl;
		ite->SEC=++tot;
	}
	rb(i,1,n){
		
		a[i].FIR=have[a[i].FIR-1]+1;
		a[i].SEC=have[a[i].SEC];
//		cout<<a[i].FIR<<" "<<a[i].SEC<<endl;
		sum[a[i].FIR]++;
//		cout<<a[i].FIR<<endl;
		sum[a[i].SEC+1]--;
	}
	rb(i,1,tot){
		sum[i]+=sum[i-1];
//		cout<<sum[i]<<endl;
	}
	rb(j,0,25){
		rb(i,1,tot){
			if(i+(1<<j)-1>tot)break;
			if(j==0) st[i][j]=sum[i];
			else st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}	
	}
	rb(i,1,n){
		int best_log=int(floor(log2(double(a[i].SEC-a[i].FIR+1))));
		int get_min=min(st[a[i].FIR][best_log],st[a[i].SEC-(1<<best_log)+1][best_log]);
//		cout<<a[i].FIR<<" "<<best_log<<endl;
//		cout<<get_min<<endl;
		if(get_min<=1){
			continue;
		}
		else{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}