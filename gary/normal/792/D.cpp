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
#define rep(i,a) for(int i=0;i<a;i++) 
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL n,q;
string s;
LL num;
LL k;
LL find_(LL now){
	LL start=(LL)(floor(log2(double(now))));
//	cout<<"*"<<start<<endl;
	rl(i,start,0){
//		cout<<now<<"-"<<((LL)(1)<<(i))<<" "<<i<<" "<<now%((LL)(1)<<(i))<<endl;
		if((now%((LL)(1)<<(i)))==0){
			return (LL)(i);
		}
	}
	return (LL)(0); 
}
void solve(){
	scanf("%I64d",&num);
	cin>>s;
	k=find_(num);
//	cout<<"*"<<k<<endl;
	int len=s.length();
	LL root=(n+1)>>1;
	rep(i,len){
		if(s[i]=='L'){
			if(k!=0){
				k--;
				num-=((LL)(1)<<k);
			}
		}
		else{
			if(s[i]=='R'){
				if(k!=0){
					k--;
					num+=((LL)(1)<<k);
				}
			} 
			else{
				if(num!=root){
					LL par1,par2;
					par1=num+((LL)(1)<<k);//left child
					par2=num-((LL)(1)<<k);
					if(par1%((LL)(1)<<(k+2))!=0){
						num=par1;
					}
					else{
						num=par2;
					}
					k++;
				}
			}
		}
//		cout<<k<<"-"<<num<<endl;
	}
	printf("%I64d\n",num);
}
int main(){
//	freopen("check.out","w",stdout);
	scanf("%I64d %I64d",&n,&q);
	while(q--){
		solve();
	}
	return 0;
}