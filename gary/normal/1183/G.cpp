#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
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
mp a[200000+10];
map<int,int> HAVE;
map<int,int> HAVE2;
map<int,int> M;
map<int,int> many;
map<int,int> :: IT ite;
bool cmp(mp A,mp B){
	return A>B;
}
void solve(){
	many.clear();
	HAVE2.clear();
	HAVE.clear();
	M.clear();
	int n;
	scanf("%d",&n);
	rb(i,1,n) {
		int c,t;
		scanf("%d %d",&c,&t);
		M[c]++;
		many[c]+=t;
	}
	int tot=0;
	for(ite=M.begin();ite!=M.end();ite++){
		a[++tot]=II(ite->SEC,many[ite->FIR]);
//		cout<<"***"<<a[tot].FIR<<" "<<a[tot].SEC<<endl;
	}
	int res2=0;
	HAVE.clear();
//	sort(a+1,a+1+tot,cmp);
	int res=0;
	rl(i,tot,1){
		while(HAVE[a[i].FIR]){
			if(HAVE2[a[i].FIR]<a[i].SEC){
				swap(a[i].SEC,HAVE2[a[i].FIR]);
			}
			a[i].SEC-=(a[i].SEC<a[i].FIR)? 0 : 1;
			a[i].FIR--;
		}
		if(a[i].FIR!=0){
			HAVE[a[i].FIR]=1;
			HAVE2[a[i].FIR]=max(0,a[i].SEC);
		}
		res+=a[i].FIR;
	}
	for(ite=HAVE.begin();ite!=HAVE.end();ite++){
		res2+=HAVE2[ite->FIR];
//		cout<<"*"<<ite->FIR<<"b<->d"<<HAVE2[ite->FIR]<<endl;
	}
	printf("%d %d\n",res,res2);
}
int main(){
//	freopen("candy.out","w",stdout);
	int QQ;
	scanf("%d",&QQ);
	while(QQ--)
	{
		solve();
	}
	return 0;
}