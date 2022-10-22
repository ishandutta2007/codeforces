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
int a[500000+10];
map<int,vector<int> > each;
int sum[500000+10];
int totc=0;
map<int,int> res;
int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n){
		sum[i]=sum[i-1]+(a[i]==c);
		totc+=(a[i]==c);
		if(a[i]!=c){
			each[a[i]].PB(i);
		}
	}
	map<int,vector<int> > :: IT ite;
	int rec=0;
	for(ite=each.begin();ite!=each.end();ite++){ 
		vector<int> tmp=ite->SEC;
		int SZ=(tmp).size();
		int tmp_rec=0;
		if(SZ) tmp_rec=1;
		rec=max(rec,tmp_rec);
		rb(i,1,SZ-1){
			tmp_rec++;
			tmp_rec-=(sum[tmp[i]]-sum[tmp[i-1]]);
			tmp_rec=max(tmp_rec,1);
			rec=max(rec,tmp_rec);
		}
	} 
	printf("%d\n",totc+rec);
	return 0;
}