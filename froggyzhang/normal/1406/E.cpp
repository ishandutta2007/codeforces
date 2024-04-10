#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define N 100010
#define B 100
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int ANS,n;
namespace grader{
	int vis[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			vis[i]=1;
		}
	}
	int Del(int x){
		int tot=0;
		for(int i=x;i<=n;i+=x){
			tot+=vis[i];
			vis[i]=0;
		}
		vis[ANS]=1;
		return tot;
	}
	int Ask(int x){
		int tot=0;
		for(int i=x;i<=n;i+=x){
			tot+=vis[i];
		}
		return tot;
	}
}
int m,p[N],pn,vis[N],res,ans,gu;
bool ntp[N];
void init(int n){
	ntp[1]=true;
	for(int i=2;i<=n;++i){
		if(!ntp[i])p[++pn]=i;
		for(int j=1;j<=pn&&p[j]*i<=n;++j){
			ntp[p[j]*i]=true;
			if(i%p[j]==0)break;
		}
	}
}
inline void Del(int x){
	printf("B %d\n",x);
	fflush(stdout);
	//grader::Del(x);
	read();
}
inline int Ask(int x){
	printf("A %d\n",x);
	fflush(stdout);
	//return grader::Ask(x);
	return read();
}
void Report(int x){
	printf("C %d\n",x);
	fflush(stdout);
} 
void calc(int i){
	for(int j=p[i];j<=n;j+=p[i]){
		if(!vis[j])--res,vis[j]=1;
	}
	int t=1;
	while(1LL*p[i]*ans<=n){
		t*=p[i];
		if(!Ask(t))break;
		ans*=p[i];
	}
}
void Solve_1(){
	for(int i=gu+1;i<=pn;i+=B){
		for(int j=i;j<=min(pn,i+B-1);++j,--res){
			Del(p[j]);
		}
		if(Ask(1)==res+1){
			for(int j=i;j<=min(pn,i+B-1);++j){
				if(Ask(p[j])){
					ans*=p[j];
					break;
				}
			}
			break;
		}
	}
}
void Solve_2(){
	for(int i=gu+1;i<=pn;++i){
		if(Ask(p[i])>=2){
			ans*=p[i];
			break;
		}
	}
}
int main(){
	n=read(),m=sqrt(n),ans=1,res=n;
	//grader::init(n);
	//ANS=99995;
	init(n);
	while(gu<pn&&p[gu+1]<=m)++gu;
	for(int i=1;i<=gu;++i)Del(p[i]);
	for(int i=1;i<=gu;++i)calc(i);
	while(1LL*ans*p[pn]>n)--pn;
	if(ans==1){
		Solve_1();
	}
	else{
		Solve_2();
	}
	Report(ans);
	return 0;
}