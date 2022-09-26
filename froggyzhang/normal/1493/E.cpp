#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
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
char s[N];
int n;
bitset<N> A,B,ans,emm;
bitset<N> Plus(const bitset<N> &a){
	bitset<N> b=a;
	for(int i=1;;++i){
		if(!a[i]){
			b[i]=1;break;
		}
		b[i]=0;
	}
	return b;
}
bitset<N> Minus(const bitset<N> &a){
	bitset<N> b=a;
	for(int i=1;;++i){
		if(a[i]){
			b[i]=0;break;
		}
		b[i]=1;
	}
	return b;
}
bitset<N> Max(const bitset<N> &a,const bitset<N> &b){
	for(int i=n;i>=1;--i){
		if(a[i]>b[i])return a;
		if(b[i]>a[i])return b;
	}
	return a;
}
bitset<N> calc(const bitset<N> &a){
	bitset<N> zyk;
	if(a[1]==1){
		zyk=emm;
		if(a[2]==0)zyk[1]=1;
	}
	else{
		zyk=a;
		if(a[2]==1)zyk[1]=1;
	}
	return zyk;
}
void Baoli(){
	for(bitset<N> i=A;;i=Plus(i)){
		for(bitset<N> j=i;;j=Plus(j)){
			ans=Max(ans,calc(i)^calc(j));
			if(j==B)break;
		}
		if(i==B)break;
	}
}

bool all_zero(const bitset<N> &a){
	for(int i=1;i<=n;++i){
		if(a[i]!=0)return false;
	}
	return true;
}
bool near(){
	bitset<N> tp=A;
	for(int i=1;i<=4;++i){
		tp=Plus(tp);
		if(tp==B)return true;
	}
	return false;
}
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		A[n-i+1]=s[i]-'0';
	}
	if(!all_zero(A)){
		A=Minus(A);
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		B[n-i+1]=s[i]-'0';
	}
	if(all_zero(B)){
		ans=emm;
	}
	else if(A[n]==0){
		ans=~emm;
	}
	else{
		if(near())Baoli();
		else{
			ans=B;
			ans[1]=1;
		}
	}
	int k=n;
	while(k>1&&!ans[k])--k;
	for(int i=k;i>=1;--i){
		putchar(ans[i]+'0');
	}
	
	return 0;
}