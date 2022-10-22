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
int a[200000+10];
map<int,int> HAVE;
map<int,int> M;
map<int,int> :: IT ite;
void solve(){
	M.clear();
	int n;
	scanf("%d",&n);
	rb(i,1,n) {
		int c;
		scanf("%d",&c);
		M[c]++;
	}
	int tot=0;
	for(ite=M.begin();ite!=M.end();ite++){
		a[++tot]=ite->SEC;
//		cout<<"*"<<ite->FIR<<"_S_"<<ite->SEC<<endl;
	}
	HAVE.clear();
	sort(a+1,a+1+tot);
	int res=0;
	rl(i,tot,1){
		while(HAVE[a[i]]){
			a[i]--;
		}
		if(a[i]!=0){
			HAVE[a[i]]=1;
		}
		res+=a[i];
	}
	printf("%d\n",res);
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