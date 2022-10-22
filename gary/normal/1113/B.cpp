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
int a[50000+10];
LL tmp_res=0,res=0;
LL sum=0;
int main(){
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
		res+=a[i];
	}
	sum=res;
	sort(a+1,a+1+n);
	rl(i,n,2){
		rb(j,1,a[i]){
			tmp_res=sum;
			if(a[i]%j==0){
				int x=j;
				tmp_res+=a[1]*(x-1);
				tmp_res-=(a[i]/j)*(j-1);
			} 
			res=min(res,tmp_res);
		}
	}
	cout<<res<<endl; 
	return 0;
}