#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
using namespace std;
typedef long long ll;
#define N 400020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,cnt,root,tot1;
multiset<int> s;
struct node{
	int val,key,ch[2],siz;
	ll sum;
}t[N]; 
#define ls t[k].ch[0]
#define rs t[k].ch[1]
inline int NewNode(int data){
	int k=++cnt;
	t[k].key=rand();
	t[k].val=t[k].sum=data;
	t[k].siz=1;
	ls=rs=0;
	return k;
}
inline void update(int k){
	t[k].siz=t[ls].siz+t[rs].siz+1;
	t[k].sum=t[ls].sum+t[rs].sum+t[k].val;
}
inline void Split1(int k,int data,int &l,int &r){
	if(!k){
		l=r=0;
		return;
	}
	if(t[k].val>=data){
		l=k;
		Split1(rs,data,rs,r);
	}
	else{
		r=k;
		Split1(ls,data,l,ls);
	}
	update(k);
}
inline void Split2(int k,int data,int &l,int &r){
	if(!k){
		l=r=0;
		return;
	}
	if(t[ls].siz+1<=data){
		l=k;
		Split2(rs,data-t[ls].siz-1,rs,r);
	}
	else{
		r=k;
		Split2(ls,data,l,ls);
	}
	update(k);
}
inline int Merge(int l,int r){
	if(!l||!r)return l|r;
	if(t[l].key<t[r].key){
		t[l].ch[1]=Merge(t[l].ch[1],r);
		update(l);
		return l;
	}
	else{
		t[r].ch[0]=Merge(l,t[r].ch[0]);
		update(r);
		return r;
	}
}
inline void Insert(int x){
	int l,r;
	Split1(root,x,l,r);
	root=Merge(Merge(l,NewNode(x)),r);
}
inline void Del(int x){
	int l,p,r;
	Split1(root,x,l,r);
	Split1(l,x+1,l,p);
	p=Merge(t[p].ch[0],t[p].ch[1]);
	root=Merge(Merge(l,p),r);
}
inline ll Query(int x){
	int l,r;
	Split2(root,x,l,r);
	ll ans=t[l].sum;
	root=Merge(l,r);
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int opt=read(),d=read();
		if(d>0){
			if(!opt){
				s.insert(d);
			}
			else ++tot1;
			Insert(d);
		} 
		else{
			if(!opt){
				s.erase(s.find(-d));
			}
			else --tot1;
			Del(-d);
		}
		ll ans=t[root].sum;
		if(tot1){
			if(!s.empty()){
				ans+=(*--s.end());
				Del(*--s.end());
			}
			ans+=Query(tot1-1);
			if(!s.empty())Insert(*--s.end());
		}
		printf("%I64d\n",ans);
	}
	return 0;
}