#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp;
char s[1000002];
inline int ask(basic_string<int>tmp){
	printf("? %u ",tmp.size());
	for(auto z:tmp)printf("%d ",z);
	puts("");fflush(stdout);
	char ss[12];scanf("%s",ss+1);
	return ss[1]=='Y';
}
inline void Solve(basic_string<int>tmp){
	if(tmp.size()==1){
		printf("! %d\n",tmp[0]);
		fflush(stdout);
		exit(0);
	}
	if(tmp.size()==2){
		printf("! %d\n",tmp[0]);
		fflush(stdout);
		char ss[12];
		scanf("%s",ss+1);
		if(ss[2]==')')exit(0);
		printf("! %d\n",tmp[1]);
		fflush(stdout);
		exit(0);
	}
	if(tmp.size()==3){
		basic_string<int>X1,X2,X3,X4;random_shuffle(tmp.begin(),tmp.end());
		for(re int i=0;i<tmp.size();++i)if(i%3==0)X1+=tmp[i];else if(i%3==1)X2+=tmp[i];else X3+=tmp[i];
		int o1=ask(X1),o2=ask(X1+X2),o3=ask(X1+X2),o4=ask(X2);
		if(o2==o3){
			if(o2)return Solve(X1+X2);
			return Solve(X3);
		}
		if(o1==1&&o4==1)return Solve(X1+X2);
		if(o1==1&&o2==1)return Solve(X1+X2);
		if(o3==1&&o4==1)return Solve(X1+X2);
		if(o1==1&&o3==1)return Solve(X1+X3);
		if(o2==1&&o4==1)return Solve(X2+X3);
		if(o2==1)return Solve(X1+X3);
		if(o3==1)return Solve(X2+X3);
		assert(0);
	}
	basic_string<int>X1,X2,X3,X4;random_shuffle(tmp.begin(),tmp.end());
	for(re int i=0;i<tmp.size();++i)if(i%4==0)X1+=tmp[i];else if(i%4==1)X2+=tmp[i];else if(i%4==2)X3+=tmp[i];else X4+=tmp[i];
	int o1=ask(X3+X4),o2=ask(X2+X4);
	if(o1==1&&o2==1)return Solve(X2+X3+X4);
	if(o1==1&&o2==0)return Solve(X1+X3+X4);
	if(o1==0&&o2==1)return Solve(X1+X2+X4);
	if(o1==0&&o2==0)return Solve(X1+X2+X3);
	assert(0);
}
int main(){
	n=read();
	basic_string<int>tmp;
	for(re int i=1;i<=n;++i)tmp+=i;
	Solve(tmp);
}