/*
Contest: -
Problem: P6303
Author: tzc_wk
Time: 2020.6.6
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
char sa[200005],sb[200005];
vector<pii> a,b;
inline void push(vector<pii> &v,pii add){
	if(v.empty())	v.push_back(add);
	else{
		if(v.back().fi==add.fi)	v.back().se+=add.se;
		else					v.push_back(add);
	}
}
bool swp=0;
vector<pii> ans;
inline void deal(int len){
//	cout<<len<<endl;
	pii bk=b.back();
//	cout<<"bk "<<bk.fi<<" "<<bk.se<<endl;
	b.pop_back();
	int sum=0;
	fd(i,len,1)	push(b,a[a.size()-i]),sum+=a[a.size()-i].se;
	fd(i,len,1)	a.pop_back();
	ans.push_back({sum,bk.se});
	push(a,bk);
}
signed main(){
	cin>>sa+1>>sb+1;
	int la=strlen(sa+1),lb=strlen(sb+1);
	fd(i,la,1)	push(a,{sa[i]-'a',1});
	fd(i,lb,1)	push(b,{sb[i]-'a',1});
	if(a.size()<b.size())	swap(a,b),swp=1;
	if(a.back().fi==b.back().fi){
		if((a.size()-b.size())%4==3)
			deal((a.size()-b.size()+1)/4*2);
		b.push_back({((b.back().fi==0)?(1):(0)),0});
		/*
		ababa
		aba
		->
		baba
		aaba
		->
		aaaba
		bba
		->
		bbba
		aaaa
		->
		aaaaa
		bbb
		*/
		deal((a.size()-b.size()+1)/4*2+1);
	}
	else{
		if(a.size()-b.size()>2)
			deal((a.size()-b.size()+1)/4*2+1);
	}
//	puts("1");
//	foreach(it,a)	putchar(it->fi+'a');
//	puts("");
//	foreach(it,b)	putchar(it->fi+'a');
//	puts("");
	while(a.size()>1||b.size()>1){
		deal(1);
//		foreach(it,a)	putchar(it->fi+'a');
//		puts("");
//		foreach(it,b)	putchar(it->fi+'a');
//		puts("");
	}
	cout<<ans.size()<<endl;
	foreach(it,ans){
		if(swp)	cout<<(it->se)<<" "<<(it->fi)<<endl;
		else	cout<<(it->fi)<<" "<<(it->se)<<endl;
	}
	return 0;
}