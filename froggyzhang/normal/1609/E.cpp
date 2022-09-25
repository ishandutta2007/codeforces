#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,Q;
char s[N];
class Segment_tree{
	int Len;
	struct node{
		int cnt[3],AB,A,B;
		node(){cnt[0]=cnt[1]=cnt[2]=0;}	
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		for(int i=0;i<3;++i){
			t[u].cnt[i]=t[ls].cnt[i]+t[rs].cnt[i];
		}
		t[u].A=min(min(t[ls].A+t[rs].cnt[1],t[ls].cnt[0]+t[rs].A),t[ls].cnt[0]+t[rs].cnt[1]);
		t[u].B=min(min(t[ls].B+t[rs].cnt[2],t[ls].cnt[1]+t[rs].B),t[ls].cnt[1]+t[rs].cnt[2]);
		t[u].AB=min(min(t[ls].AB+t[rs].cnt[2],t[ls].cnt[0]+t[rs].AB),t[ls].A+t[rs].B);
	}
	void build(int u,int L,int R){
		if(L==R){
			t[u].cnt[s[L]-'a']=1;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		update(u);
	}
	void _change(int u,int L,int R,int p){
		if(L==R){
			t[u].cnt[0]=t[u].cnt[1]=t[u].cnt[2]=0;
			t[u].cnt[s[p]-'a']=1;
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?_change(ls,L,mid,p):_change(rs,mid+1,R,p);
		update(u);
	}
public:
	void init(int n){
		Len=n;
		build(1,1,Len);
	}
	void Change(int p){
		_change(1,1,Len,p);		
	}
	int get_ans(){
		return t[1].AB;
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	cin>>(s+1);
	T.init(n);
	while(Q--){
		int p;
		cin>>p;
		cin>>s[p];
		T.Change(p);
		cout<<T.get_ans()<<'\n';
	}
	return 0;
}