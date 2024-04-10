#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 500005
int n,a[maxn];
set<pii>s;
int val,two,sgn,add;

void getval(int x,int lst)
{
	if(two!=-1){
		val+=2; s.clear(); sgn=1,add=0;
		if(x-two>0) s.insert(mkp(x-two,x-two));
		return;
	}
	if(!s.size()){
		if(lst!=-1) s.insert(mkp(1,min(lst,x)-1));
		sgn=-1,add=x;
		return;
	}
	if(sgn==1){
		while(s.size() && (--s.end())->fi >= x-add)
			s.erase(--s.end());
		if(s.size() && (--s.end())->se >= x-add){
			int L=(--s.end())->fi;
			s.erase(--s.end());
			s.insert(mkp(L,x-add-1));
		}
	}else{
		while(s.size() && add-(s.begin())->se >=x )
			s.erase(s.begin());
		if(s.size() && add-(s.begin())->fi >=x){
			int R=(s.begin())->se;
			s.erase(s.begin());
			s.insert(mkp(add-x+1,R)); 
		}
	}
	val++,sgn*=-1,add=x-add;
}
void change(int x)
{
	two=-1; if(x%2)return;
	int t=sgn*((x/2)-add);
	set<pii>::iterator it=s.lower_bound(mkp(t+1,t+1));
	bool ins=1;
	if(it!=s.begin()){
		--it;
		int L=it->fi,R=it->se;
		if(L<=t && R>=t){
			s.erase(it);
			if(L!=t) s.insert(mkp(L,t-1));
			if(t!=R) s.insert(mkp(t+1,R));
			two=x/2,ins=0;
		}
	}
	if(ins) s.insert(mkp(t,t)); 
}

void work()
{
	n=read();
	For(i,1,n)a[i]=read();
	val=0,two=-1;
	sgn=1,add=0;
	s.clear(); // one  
	For(i,1,n)
	{
		//  X*sgn+add=c
		// X=sgn*(c-add) 
		int x=a[i];
		getval(x,i==1?-1:a[i-1]);
		change(x);
	}
	if(two!=-1)printf("%lld\n",2*n-val-2);
	else if(s.size())printf("%lld\n",2*n-val-1);
	else printf("%lld\n",2*n-val);
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}