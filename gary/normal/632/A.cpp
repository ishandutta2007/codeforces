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
LL have=0;
LL money=0;
string s[45];
int main(){
	int n,p;
	scanf("%d %d",&n,&p);
	rb(i,1,n){
		cin>>s[i];
	}
	rl(i,n,1){
		if(s[i]=="half"){
			have*=2;
		}
		else{
			have*=2;
			have++;
		}
	}
//	cout<<have<<endl;
	rb(i,1,n){
		if(s[i]=="half"){
			money+=(have/2)*p;
			have/=2;
		}
		else{
			money+=(have/2)*p+p/2;
			have/=2;
		}
	}
	printf("%I64d\n",money);
	return 0;
}