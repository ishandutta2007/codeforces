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
vector<int> each[100000+10]; 
vector<int> sum[100000+10];
bool cmp2(int A,int B){
	return A>B;
}
bool cmp(vector<int> A,vector<int> B){
	return A.size()>B.size();
}
int main(){
	int n,m;
	cin>>n>>m;
	rb(i,1,n){
		int si,ri;
		scanf("%d %d",&si,&ri);
		each[si].PB(ri);
	}
	rb(i,1,m){
		sort(each[i].begin(),each[i].end(),cmp2);
	}
	sort(each+1,each+1+m,cmp);
	rb(i,1,m){
		int SZ=each[i].size();
		if(SZ){
			sum[i].PB(each[i][0]);
		}
		if(SZ)
		rb(j,1,SZ-1){
			sum[i].PB(sum[i][j-1]+each[i][j]);	
		} 
	}
	int res=0;
	rb(i,1,n){
		int Sum=0;
		rb(j,1,m){
			if(each[j].size()<i){
				break;
			}
			if(sum[j][i-1]>0) 
			Sum+=sum[j][i-1];
		}
		res=max(res,Sum);
	}
	printf("%d\n",res);
	return 0;
}