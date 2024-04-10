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
vector<mp> res;
int n,a[300000+10];
map<int,int> tot;
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
	}
	int las=0;
	rb(i,1,n){
		tot[a[i]]++;
		if(tot[a[i]]==2){
			tot.clear();
			res.PB(II(las+1,i));
			las=i;
			continue;
		}
		if(i==n){
			if(!res.empty()){
				res[res.size()-1].SEC=n;
			}
			else{
				puts("-1");
				return 0;
			}
		}
	}
	int SZ=res.size();
	printf("%d\n",SZ);
	rep(i,SZ){
		printf("%d %d\n",res[i].FIR,res[i].SEC);
	}
	return 0;
}