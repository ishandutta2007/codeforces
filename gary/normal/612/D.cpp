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
#define rep(i,a) for(int i=0;i<a;++i)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<mp > res,tim;
int main(){
	int n,k;
	cin>>n>>k;
	rb(i,1,n){
		int li,ri;
		scanf("%d%d",&li,&ri);
		tim.PB(II(li,-1));//open
		tim.PB(II(ri,1));//close
	}
	sort(tim.begin(),tim.end());
	vector<mp > :: IT ite;
	int cnt=0;
	int las=-INF;
	for(ite=tim.begin();ite!=tim.end();ite++){
		if((*ite).SEC==1){
			if(cnt==k){
				res.PB(II(las,(*ite).FIR));
			}
			cnt--;
		}
		else{
			if(cnt==k-1){
				las=(*ite).FIR;
			}
			cnt++;	
		}
	}
	printf("%d\n",res.size());
	rep(i,res.size()){
		printf("%d %d\n",res[i].FIR,res[i].SEC);
	}
	return 0;
}