#include<bits/stdc++.h>
using namespace std;
#define N 1000020
typedef long long ll;
int n,Q;
char s[N];
class Segment_Tree{
	struct node{
		int cl,cr,len;
		node(){cl=cr=len=0;}
		friend node operator + (const node &a,const node &b){
			if(!a.len)return b;
			if(!b.len)return a;
			node c;
			if(a.cr^b.cl){
				c.len=a.len+b.len;
				c.cl=a.cl,c.cr=b.cr;
			}
			else if(a.len<b.len){
				c.len=b.len-a.len;
				c.cl=b.cl^(a.len&1);
				c.cr=b.cr;
			}
			else{
				c.len=a.len-b.len;
				c.cl=a.cl;
				c.cr=a.cr^(b.len&1);
			}
			return c;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
public:
	void build(int u,int L,int R){
		if(L==R){
			t[u].len=1;
			t[u].cl=t[u].cr=(s[L]==')'||s[L]=='(');
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		t[u]=t[ls]+t[rs];
	}
	node Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r)return t[u];
		int mid=(L+R)>>1;
		node ans;
		if(l<=mid)ans=ans+Query(ls,L,mid,l,r);
		if(r>mid)ans=ans+Query(rs,mid+1,R,l,r);
		return ans;
	}
	int get_ans(int l,int r){
		auto t=Query(1,1,n,l,r);
		return t.len/2;	
	}
}T;
void Solve(){
	cin>>(s+1);
	n=strlen(s+1);
	T.build(1,1,n);
	cin>>Q;
	while(Q--){
		int l,r;
		cin>>l>>r;
		cout<<T.get_ans(l,r)<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}