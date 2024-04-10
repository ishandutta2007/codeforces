// Problem: E. Colorful Operations
// Contest: Codeforces Round #771 (Div. 2)
// URL: https://codeforces.com/contest/1638/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
/////
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int tree[1000003];
void add(int x,int k)
{
	while(x<=1000000) tree[x]+=k,x+=x&(-x);
	return ;
}
void update(int l,int r,int k)
{
	add(l,k),add(r+1,-k);
}
int find(int x)
{
	int res=0;
	while(x) res+=tree[x],x-=x&(-x);
	return res; 
}
struct Node{
    int l,r;
    mutable int val;
    Node(int a=-1,int b=-1,int c=0){l=a,r=b,val=c;}
    bool operator<(const Node&a)const{return l<a.l;}
};
set<Node> st;
map<int,int> tag;
set<Node>::iterator split(int pos)
{
    auto it=st.lower_bound(Node(pos));
    if (it!=st.end()&&it->l==pos) return it;
    --it;Node tmp=*it;st.erase(it);
    st.insert(Node(tmp.l,pos-1,tmp.val));
    return st.insert(Node(pos,tmp.r,tmp.val)).first; 
}
void assign(int l,int r,int val)
{
	auto itr=split(r+1),itl=split(l);
	for(auto i=itl; i!=itr; ++i)
		update(i->l,i->r,tag[i->val]-tag[val]);
    st.erase(itl,itr),st.insert((Node){l, r, val});
}
int getcol(int x)
{
	auto it=st.lower_bound((Node){x,0,0});
	if(it!=st.end()&&it->l==x) return it->val;
	else
	{
		--it;
		assert(it->l<=x&&x<=it->r);
		return it->val;
	}
}
signed main()
{
	char s[13];
	int n=read(),m=read();
	st.insert((Node){-100,n+100,1});
	for(int x,y,z; m--;)
	{
		scanf("%s",s);
		if(s[0]=='A')
		{
			x=read(),y=read();
			tag[x]+=y;
		}
		else if(s[0]=='C')
		{
			x=read(),y=read(),z=read();
			assign(x,y,z);
		}
		else
		{
			x=read();
			printf("%lld\n",find(x)+tag[getcol(x)]);
		}
	}
	return 0;
}