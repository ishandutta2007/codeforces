#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005;
int n,m1,m2;std::bitset<N> f1[N],f2[N];bool can1[N],can2[N];
inline int op(int x){return x<=n?x+n:x-n;}
void init(std::bitset<N> *f,int m){
	for(int i=1;i<=n+n;++i)f[i].set(i);
	for(int i=1,x,y;i<=m;++i){
		read(x,y);
		if(x<0)x=-x+n;
		if(y<0)y=-y+n;
		f[op(x)].set(y),f[op(y)].set(x);
	}
	for(int k=1;k<=n+n;++k)for(int i=1;i<=n+n;++i)if(f[i].test(k))f[i]|=f[k];
}
std::bitset<N> cons(std::bitset<N> *f,std::bitset<N> cur){
	std::bitset<N> ans;
	for(int i=1;i<=n;++i){
		if(cur.test(i)||cur.test(i+n))continue;
		std::bitset<N> tmp=cur|f[i];
		bool flag=0;for(int i=1;i<=n;++i)flag|=tmp.test(i)&&tmp.test(i+n);
		if(flag)cur|=f[i+n];else cur|=f[i];
	}
	for(int i=1;i<=n;++i)if(cur.test(i))ans.set(i);
	return ans;
}
int main(){
	read(n,m1,m2),init(f1,m1),init(f2,m2);
	for(int i=1;i<=n+n;++i){
		bool A=0,B=0;
		for(int j=1;j<=n;++j)A|=f1[i].test(j)&&f1[i].test(j+n);
		for(int j=1;j<=n;++j)B|=f2[i].test(j)&&f2[i].test(j+n);
		can1[i]=!A,can2[i]=!B;
	}
	bool F1=1,F2=1;
	for(int i=1;i<=n;++i)F1&=!f1[i].test(i+n)||!f1[i+n].test(i),F2&=!f2[i].test(i+n)||!f2[i+n].test(i);
	if(F1==0&&F2==0)return puts("SIMILAR"),0;
	for(int i=1;i<=n+n;++i)if(can1[i]!=can2[i]){
		std::bitset<N> ans=can1[i]?cons(f1,f1[i]):cons(f2,f2[i]);
		for(int i=1;i<=n;++i)printf("%d%c",ans.test(i)," \n"[i==n]);
		return 0;
	}
	for(int i=1;i<=n+n;++i)if(can1[i]&&can1[op(i)]&&can2[i]&&can2[op(i)]){
		for(int j=1;j<=n+n;++j)if(can1[j]&&can1[op(j)]&&can2[j]&&can2[op(j)]&&f1[i].test(j)!=f2[i].test(j)){
			std::bitset<N> ans,cur;cur.set(i),cur.set(op(j));
			ans=f1[i].test(j)?cons(f2,cur):cons(f1,cur);
			for(int i=1;i<=n;++i)printf("%d%c",ans.test(i)," \n"[i==n]);
			return 0;
		}
	}
	puts("SIMILAR");
	return 0;
}