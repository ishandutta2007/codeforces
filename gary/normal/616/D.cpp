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
pair<int,mp> res;
map<int,int> tot;
int have=0;
int a[500000+10];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	int l=0;
	have=0;
	res=II(-INF,II(-INF,-INF));
	rb(i,1,n){
		if(i!=1){
			tot[a[i-1]]--;
//			cout<<a[i-1]<<" "<<i<<endl;
			if(tot[a[i-1]]==0){
				have--;
			}
		}
		if(l<i){
			l=i;
			have++;
			tot[a[i]]++;
		}
//		cout<<i<<" "<<l<<" "<<have<<endl;
		while(l<n){
			l++;
			tot[a[l]]++;
//			cout<<a[l]<<tot[a[l]]<<endl;
			if(tot[a[l]]==1&&have==k){
				tot[a[l]]--;
				l--;
				break;
			}
			if(tot[a[l]]==1){
				have++;
			}
		}
//		cout<<tot[2]<<endl;
//		cout<<i<<" "<<l<<" "<<have<<endl;
		res=max(res,II(l-i+1,II(i,l)));
	}
	printf("%d %d\n",res.SEC.FIR,res.SEC.SEC);
	return 0;
}