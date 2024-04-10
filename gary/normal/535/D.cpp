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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int flag[1000000+10];
int n,m;
int len;
string p;
const int MOD=1e9+7;
int z[2000000+10];
void calc(){
	rb(i,2,len) {
		if(p[i]!=p[i-1]) break;
		z[2]++;
	}
	int l_bound=2,r_bound=2+z[2]-1;
	rb(i,3,len){
		if(i<=r_bound)
		{
			z[i]=z[i-l_bound+1];
			z[i]=min(z[i],r_bound-i+1);
			if(z[i]+i-1==r_bound){
				int ite=z[i]+1;
				rb(j,r_bound+1,len){
					if(p[j]!=p[ite++]) break;
					z[i]++;
				}
				l_bound=i;
				r_bound=i+z[i]-1;
			}
		}
		else{
			int ite=1;
			rb(j,i,len){
				if(p[j]!=p[ite++]) break;
				z[i]++;
			}
			l_bound=i;
			r_bound=i+z[i]-1;
		}
	}
}
int final_z[1000000+10];
string saveP;
int main(){
	scanf("%d %d",&n,&m);
	cin>>p;
	saveP=p; 
	p=p+'$'+p;
	len=p.length();
//	cout<<len<<endl;
	p='$'+p;
	calc();
//	cout<<z[2]<<endl;
//	cout<<p<<endl;
//	cout<<"$$";
//	rb(i,2,len) cout<<z[i];
//	cout<<endl;
	p=saveP;
	rb(i,1,p.length()){
//		cout<<i<<" "<<
		final_z[i]=z[i+p.length()+1];
	}
	rep(i,m){
		int yi;
		scanf("%d",&yi);
		flag[yi]=1;
	}
	int ite=1;
	LL RES=1;
	for(ite;ite<=n;ite++){
//		cout<<ite<<endl;
		if(flag[ite])
		for(int cnt=1;cnt<=p.length();cnt++){
			if(flag[ite]){
				if(final_z[cnt]!=p.length()-cnt+1){
					puts("0");
					return 0;
				}
				cnt=1;
			}
			if(cnt!=p.length())ite++;
		}
		else{
			RES*=(LL)(26);
			RES%=MOD;
		}
	}
	printf("%I64d\n",RES); 
	return 0;
}