#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;
#define N 200010
typedef long long ll;
const ll inf=1LL<<61;
map<ll,int> mp;
inline ll read(){
    ll x=0,f=1;
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
int m,root,cnt=0;
struct node{
	int key,num,ch[2],rev;
	ll mn[2],l,r,siz;
	bool Rev(){
		num^=1;
		rev^=1;
		swap(mn[0],mn[1]);
	}
}t[N<<4];
int NewNode(int num,ll l,ll r){
	int k=++cnt; 
	t[k].num=num;
	t[k].l=l,t[k].r=r;
	t[k].siz=r-l+1;
	t[k].key=rand();
	t[k].ch[0]=t[k].ch[1]=0;
	if(num==0){
		t[k].mn[0]=l;
		t[k].mn[1]=inf;
	}
	else{
		t[k].mn[0]=inf;
		t[k].mn[1]=l;
	}
	mp[r]=k;
	return k;
}
void pushdown(int k){
	if(t[k].rev){
		t[t[k].ch[0]].Rev();
		t[t[k].ch[1]].Rev();
		t[k].rev=0;
	}
}
void update(int k){
	t[k].mn[0]=t[k].mn[1]=inf;
	t[k].siz=t[t[k].ch[0]].siz+t[t[k].ch[1]].siz+t[k].r-t[k].l+1;
	if(t[k].num==0){
		t[k].mn[0]=t[k].l;
	}
	else{
		t[k].mn[1]=t[k].l;
	}
	if(t[k].ch[0]){
		for(int i=0;i<=1;i++)
		t[k].mn[i]=min(t[k].mn[i],t[t[k].ch[0]].mn[i]);
	}
	if(t[k].ch[1]){
		for(int i=0;i<=1;i++)
		t[k].mn[i]=min(t[k].mn[i],t[t[k].ch[1]].mn[i]);
	}
}
void Split(int k,ll data,int &l,int &r){
	if(!k){
		l=r=0;
		return;
	}
	pushdown(k);
	if(t[k].r<=data){
		l=k;
		Split(t[k].ch[1],data,t[k].ch[1],r);
	}
	else{
		r=k;
		Split(t[k].ch[0],data,l,t[k].ch[0]);
	}
	update(k);
}
int Merge(int l,int r){
	if(!l||!r)return l+r;
	pushdown(l),pushdown(r);
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
void del(int k){;
	mp.erase(mp.lower_bound(t[k].r));
	if(t[k].ch[0])del(t[k].ch[0]);
	if(t[k].ch[1])del(t[k].ch[1]);
}
void New(ll pos){
	int k=mp.lower_bound(pos)->second;
	
	int l=0,r=0,p=0;
	int num=t[k].num;
	ll x=t[k].l,y=t[k].r;
	if(x==y&&x==pos)return;
	Split(root,y,l,r);
	Split(l,x-1,l,p);
	del(p);
	if(pos>x){
		l=Merge(l,NewNode(t[k].num,x,pos-1));
	}
	if(y>pos){
		r=Merge(NewNode(t[k].num,pos+1,y),r);
	}
	root=Merge(l,Merge(NewNode(t[k].num,pos,pos),r));
}
void Change(ll x,ll y,int num){
	int l=0,p=0,r=0;
	New(x),New(y);
	Split(root,y,l,r);
	Split(l,x-1,l,p);
	del(p);
	root=Merge(l,Merge(NewNode(num,x,y),r));
}
void Rev(ll x,ll y){
	int l=0,p=0,r=0;
	New(x),New(y);
	Split(root,y,l,r);
	Split(l,x-1,l,p);
	t[p].Rev();
	root=Merge(l,Merge(p,r));
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	srand(time(0));
	m=read();
	root=Merge(root,NewNode(0,1,2000000000000000000LL));
	for(int i=1;i<=m;i++){
		int opt=read();
		ll l=read(),r=read();
		if(opt==1){
			Change(l,r,1);
		}
		else if(opt==2){
			Change(l,r,0);
		}
		else{
			Rev(l,r);
		}
		printf("%lld\n",t[root].mn[0]);
	}
	return 0;
}
/*
4
1 1 10
1 2 20
1 2 10
2 3 9
*/
/*
4
1 2 2
1 1 2
2 2 2
1 2 6
*/