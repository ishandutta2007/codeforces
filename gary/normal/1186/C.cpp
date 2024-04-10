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
int main(){
	string A,B;
	//|A||B|
	cin>>A>>B;
	int lena=A.length(),lenb=B.length();
	int totB=0,totA=0;
	rb(i,1,lenb){
		totB+=(B[i-1]=='1');
		totA+=(A[i-1]=='1');
	} 
	int res=0;
	if((totB&1)==(totA&1)){
		res++;
	}
	rb(i,lenb,lena-1){
		totA-=A[i-lenb];
		totA+=A[i];
		res+=((totB&1)==(totA&1)); 
	}
	printf("%d\n",res);
	return 0;
}