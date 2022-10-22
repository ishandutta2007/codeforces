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
int n;
LL p[500000+10];
string s;
LL sum1[500000+10],sumb[500000+10],sum2[500000+10],sum2b[500000+10];
LL final,tmp;
int main(){
	scanf("%d",&n);
	rb(i,1,n)
	{
		scanf("%I64d",&p[i]);
		sum1[i]=sum1[i-1]+p[i];
	}
	cin>>s;
	rb(i,1,n){
		LL this_=p[i]*bool(s[i-1]=='B');
		sumb[i]=sumb[i-1]+this_;
	}
	final=sumb[n];
	rl(i,n,1){
		sum2[i]=sum2[i+1]+p[i];
		LL this_=p[i]*bool(s[i-1]=='B');
		sum2b[i]=sum2b[i+1]+this_;
	}
	rb(i,1,n){
		tmp=sum2b[i+1];
		tmp+=sum1[i]-sumb[i];
		final=max(final,tmp);
	}
	rl(i,n,1){
		tmp=sumb[i-1];
		tmp+=sum2[i]-sum2b[i];
		final=max(final,tmp);
	}
	printf("%I64d\n",final);
	return 0;
}