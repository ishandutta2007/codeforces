#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;a++)
#define rl(a,b,c) for(LL a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
LL n,m,q;//	<=5e5
map<LL,LL> fir_n_y; 
mp each_c[500000+10];
LL res[500000+10];
mp x_l[500000+10]; 
int tree[500000*8];
int size_n;
pair<LL,LL> each_q[500000+10];
LL j_s=0;
bool m_cmp(mp A,mp B){
	return A.SEC<B.SEC;
}
void _add(int point){
//	cout<<"*"<<point<<endl;
	int now=point+size_n-1;
	tree[now]++;
	int now_change=now>>1;
	while(now_change){
		tree[now_change]=tree[now_change<<1]+tree[(now_change<<1)+1];
		now_change>>=1;
	} 
}
int query(int now,int l,int r,int a,int b,int k){
//	cout<<"*"<<l<<" "<<r<<" "<<a<<" "<<b<<" "<<k<<endl;
	if(l==r-1){
		return l;
	}
	int mid=(l+r)>>1;
	if(k-tree[now<<1]<=0){
		return query(now<<1,l,mid,a,b,k);
	}
	else{
		return query((now<<1)+1,mid,r,mid,b,k-tree[now<<1]);
	}
}
int _query(int l,int r,int k){
	return query(1,1,size_n+1,l,r,k); 
}
int main(){
//	freopen("Irrigation.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	size_n=(1<<int(ceil(log2(double(m)))));
	rb(i,1,n){
		LL ai;
		cin>>ai;
		fir_n_y[ai]++;
	}
	rb(i,1,m){
		each_c[i].SEC=i;
		each_c[i].FIR=fir_n_y[i];
		
	}
	sort(each_c+1,each_c+1+m);
	rb(i,1,q){
		cin>>each_q[i].FIR;
		each_q[i].SEC=i;
	}
	sort(each_q+1,each_q+1+q);
	rb(i,1,m){
		x_l[i]=each_c[i];
	}
	LL l=1;
	j_s=n;
	_add(each_c[1].SEC);
	rb(i,1,m-1){
		while(l<=q&&(each_q[l].FIR-j_s)<=(LL)i*((LL)each_c[i+1].FIR-(LL)each_c[i].FIR)){
			LL m_n=(each_q[l].FIR-j_s)%i;
			if(m_n==0) m_n=i;
			res[each_q[l].SEC]=_query(1,size_n+1,m_n);
			l++;
		}
		j_s+=(LL)i*((LL)each_c[i+1].FIR-(LL)each_c[i].FIR);//cout<<(LL)each_c[i+1].FIR<<" "<<(LL)each_c[i].FIR<<endl;
		_add(each_c[i+1].SEC);
	}
	sort(x_l+1,x_l+1+m,m_cmp);
	rb(i,l,q){
		LL m_n=(each_q[i].FIR-j_s)%m;
		if(m_n==0) m_n=m;
		res[each_q[i].SEC]=x_l[m_n].SEC; 
	}
	rb(i,1,q){
		cout<<res[i]<<endl;
	}
	return 0;
}