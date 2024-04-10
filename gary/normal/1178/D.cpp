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
//int tot_path;
int shai[499510];
void SHAI(){
	shai[1]=1;
	rb(i,2,499500){
		if(!shai[i]){
			int now=i*2;
			while(now<=49950){
				shai[now]=1;
				now+=i;
			}
		}
	}
}
vector<mp > RES; 
//map<mp,int> used;
int main(){
	int n;
	scanf("%d",&n);
//	tot_path=n*(n-1);
//	tot_path/=2;
	SHAI();
	int res=n-1;
	rb(i,1,n-1){
		RES.PB(II(i,i+1));
	}
	res++;
	RES.PB(II(n,1));
	if(shai[res]){
		int now=1;
		while(now+2<=n){
			res++;
			RES.PB(II(now,now+2));
			if(!shai[res]) break;
			now++;
			if(now+2<=n){
			res++;
			RES.PB(II(now,now+2));
			}
			if(!shai[res]) break;
			now+=3;
		}
	}
	cout<<res<<endl;
	rb(i,0,res-1){
		printf("%d %d\n",RES[i].FIR,RES[i].SEC);
	} 
	return 0;
}