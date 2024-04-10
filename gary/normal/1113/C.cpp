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
int a[300000+10];
int sum[300000+10];
int flag[300000+10];
map<int,vector<int>  > M1;
map<int,vector<int>  > M2;
map<int,int> tot1,tot2;
 LL res=0;
int main(){
	int n;
	scanf("%d",&n);
	M2[0].PB(0);
	rb(i,1,n){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
//		cout<<sum[i]<<endl;
		if(i&1)M1[sum[i]].PB(i);
		else M2[sum[i]].PB(i);
	}
	map<int,vector<int> > :: IT ite;
	for(ite=M1.begin();ite!=M1.end();ite++){
		int SZ=(ite->SEC).size();
//		cout<<ite->FIR<<" "<<SZ<<endl;
		LL tmpres=(LL)(SZ)*(LL)(SZ-1);
		tmpres>>=1; 
		res+=tmpres;
	}
	M1=M2;
	for(ite=M1.begin();ite!=M1.end();ite++){
		int SZ=(ite->SEC).size();
//		cout<<ite->FIR<<" "<<SZ<<endl;
		LL tmpres=(LL)(SZ)*(LL)(SZ-1);
		tmpres>>=1; 
		res+=tmpres;
	}
//	map<int,vector< int> > :: IT ite;
//	vector<int> tmp;
//	for(ite=M1.begin();ite!=M1.end();ite++){
//		tmp=ite->SEC;
//		sort(tmp.begin(),tmp.end());
//		ite->SEC=tmp;
//		tot1[ite->FIR]=0;
//	}
//	for(ite=M2.begin();ite!=M2.end();ite++){
//		sort((ite->SEC).begin(),(ite->SEC).end());
//		tot2[ite->FIR]=0;
//	}
	
//	for(ite=M1.begin();ite!=M1.end();ite++){
//		int now1=ite->FIR;
//		vector<int> now2=ite->SEC;
//		vector<int> now3=M2[ite->FIR];
//		int SZ2=M2[ite->FIR].size();
//		rep(i,now2.size()){
//			cout<<now1<<" "<<now2[i]<<endl;
////			cout<<i<<endl;
//			while(tot2[ite->FIR]+1<=SZ2&&now3[tot2[ite->FIR]]<now2[i]){
//				tot2[ite->FIR]++;
//			}
//			res+=tot2[ite->FIR];
//		}
//		
//	}
//	swap(M1,M2);
//	swap(tot1,tot2);
//	for(ite=M1.begin();ite!=M1.end();ite++){
//		int now1=ite->FIR;
//		vector<int> now2=ite->SEC;
//		vector<int> now3=M2[ite->FIR];
//		int SZ2=M2[ite->FIR].size();
//		rep(i,now2.size()){ 
//			cout<<now1<<" "<<now2[i]<<endl;
//			while(tot2[ite->FIR]+1<=SZ2&&now3[tot2[ite->FIR]]<now2[i]){
//				tot2[ite->FIR]++;
//			}
//			res+=tot2[ite->FIR];
//		}
//		
//	}
	cout<<res<<endl;
	return 0;
}